#include "sendfile.h"

sendfile::sendfile(QObject *parent) : QObject(parent)
{

}

void sendfile::connectserver(QString ip, unsigned short port)
{
    m_Tcpsocket=new QTcpSocket;
    m_Tcpsocket->connectToHost(QHostAddress(ip),port);
#if 0
    connect(m_Tcpsocket,&QTcpSocket::connected,this,[=]()
    {
        emit connectOK();
    });
#else
    connect(m_Tcpsocket,&QTcpSocket::connected,this,&sendfile::connectOK);
#endif
    connect(m_Tcpsocket,&QTcpSocket::disconnected,this,[=]()
    {
        m_Tcpsocket->close();
        m_Tcpsocket->deleteLater();
        emit disconnectOK();
    });
}

void sendfile::SENDFILE(QString path)
{
    if(path.isEmpty())
    {
        return;
    }

    QFile file(path);
    QFileInfo info(path);
    file.open(QFile::ReadOnly);
    int file_size=info.size();

    while(!file.atEnd())
    {
       static int num=0;
       if(num==0)
       {
           m_Tcpsocket->write((char *)&file_size,4);
       }
       QByteArray data=file.readLine();
       num+=data.size();
       int PERCENT=num*100/file_size;
       emit progress(PERCENT);
       m_Tcpsocket->write(data.data());
    }
}
