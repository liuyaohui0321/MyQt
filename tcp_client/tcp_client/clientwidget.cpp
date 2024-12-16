#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    QTcpSocket *tcpSocket = new QTcpSocket(this);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}


void ClientWidget::on_pushButtonConnect_clicked()
{
    QString ipaddr=ui->lineEditIP->text();
    QString port=ui->lineEditPORT->text();
    tcpSocket->connectToHost(ipaddr, port);

    connect(tcpSocket, &QTcpSocket::readyRead, this, [=]()
    {
        QByteArray data=QTcpSocket.readAll();
    });// 读取数据
}

