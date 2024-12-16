#include "recvfile.h"

RecvFile::RecvFile(QTcpSocket *tcp,QObject *parent) : QThread(parent)
{
    m_tcp=tcp;
}

// 接收数据
void RecvFile::run()
{
    QFile *file=new QFile("Recv.txt");
    file->open(QFile::WriteOnly);
    connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
    {
        static int count=0;
        static int total=0;
        if(count==0)
        {
            m_tcp->read((char *)&total,4);
        }
        // 接收剩余数据
        QByteArray data=m_tcp->readAll();
        file->write(data);
        count+=data.size();

        // 判断数据是否接收完成
        if(count==total)
        {
            m_tcp->close();
            m_tcp->deleteLater();
            file->close();
            file->deleteLater();
            emit over();
        }

    });

    //进入事件循环
    exec();

}
