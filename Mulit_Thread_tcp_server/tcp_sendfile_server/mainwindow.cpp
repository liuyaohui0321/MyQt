#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->portline->setText("8511");
    m_TcpServer=new QTcpServer(this);
    m_TcpSocket=NULL;
    connect(m_TcpServer,&QTcpServer::newConnection,this,[=]()
    {
        m_TcpSocket=m_TcpServer->nextPendingConnection();
        unsigned short port=m_TcpSocket->peerPort();
        QString ip=m_TcpSocket->peerAddress().toString();
        QString temp=QString("[%1:%2]:成功连接").arg(ip).arg(port);
        ui->readtext->append(temp);
        //创建子线程
        RecvFile *worker=new RecvFile(m_TcpSocket);
        worker->start();
        connect(worker,&RecvFile::over,this,[=]()
        {
            worker->quit();
            worker->wait();
            worker->deleteLater();
            QMessageBox::information(this,"File Receive","File Receive Finished");
        });
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    unsigned short port=ui->portline->text().toUShort();
    m_TcpServer->listen(QHostAddress::Any,port);
}

