#include "serverwidget.h"
#include "ui_serverwidget.h"


ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpServer=new QTcpServer(this);//监听套接字
    tcpServer->listen(QHostAddress::Any,8511);
    setWindowTitle("服务器：8511");
    tcpSocket=NULL;

    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
            {
                tcpSocket=tcpServer->nextPendingConnection();//用于通信的套接字
                //获取客户端ip和端口号
                QString ip =tcpSocket->peerAddress().toString();
                quint16 port=tcpSocket->peerPort();
                QString temp=QString("[%1:%2]:成功连接").arg(ip).arg(port);
                ui->textEditread->setText(temp);
                //通信
                connect(tcpSocket,&QTcpSocket::readyRead,
                    [=]()
                    {
                        QByteArray Array=tcpSocket->readAll();
                        ui->textEditread->append(Array);//不覆盖原来内容
                    }
                );
            }

     );

}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_ButtonSend_clicked()
{
    if(tcpSocket==NULL)
    {
        return;
    }
    //获取编辑区内容
    QString str=ui->textEditwrite->toPlainText();

    tcpSocket->write(str.toUtf8().data());
}

void ServerWidget::on_ButtonClose_clicked()
{
    if(tcpSocket==NULL)
    {
        return;
    }
    //主动和客户端断开连接
    QString ip =tcpSocket->peerAddress().toString();
    quint16 port=tcpSocket->peerPort();
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket==NULL;
    QString temp=QString("服务器与客户端[%1:%2]断开连接").arg(ip).arg(port);
    ui->textEditread->append(temp);
}

