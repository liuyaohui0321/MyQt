#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->portline->setText("8511");
    setWindowTitle("服务器：8511");
    m_TcpServer =new QTcpServer(this);
    m_TcpSocket=NULL;

    connect(m_TcpServer,&QTcpServer::newConnection,this,[=]()
    {
        m_TcpSocket=m_TcpServer->nextPendingConnection();

        m_status->setPixmap(QPixmap(":/connect.png").scaled(30,30));

        //再加一个connect操作，以确定什么时候有数据过来，然后接收数据，但是必须是在连接客户端的情况下
        connect(m_TcpSocket,&QTcpSocket::readyRead,this,[=]()
        {
            QByteArray data=m_TcpSocket->readAll();
            ui->readtext->append("服务端接收："+QString::fromUtf8(data));
            //也可以  ui->readtext->append("服务端接收："+data);
        });

        connect(m_TcpSocket,&QTcpSocket::disconnected,this,[=]()
        {
            m_TcpSocket->close();
            m_TcpSocket->deleteLater();
            m_status->setPixmap(QPixmap(":/disconnect.png").scaled(30,30));
            ui->setlistenButton->setDisabled(false);//点击连接就会恢复
        });


    });

    //状态栏
    m_status=new QLabel;
    m_status->setPixmap(QPixmap(":/disconnect.png").scaled(30,30));
    ui->statusbar->addWidget(new QLabel("连接状态："));
    ui->statusbar->addWidget(m_status);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_setlistenButton_clicked()
{
    unsigned short port=ui->portline->text().toUShort();
    if(true==m_TcpServer->listen(QHostAddress::Any,port));
    {
        ui->setlistenButton->setDisabled(true);//点击连接就会变灰
    }
}


void MainWindow::on_sendButton_clicked()
{
    if( m_TcpSocket==NULL)
    {
        return;
    }
    QString msg=ui->sendtext->toPlainText();
    m_TcpSocket->write(msg.toUtf8().data());
    ui->readtext->append("服务端发送："+msg);
}

