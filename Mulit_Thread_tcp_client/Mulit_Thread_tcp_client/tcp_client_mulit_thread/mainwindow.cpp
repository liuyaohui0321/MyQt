#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setWindowTitle("客户端");//会报错
    setWindowTitle("客户端：8511");
    ui->PORTline->setText("8511");
    ui->IPline->setText("127.0.0.1");
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);   
    QThread *t=new QThread(this);  //创建一个子线程
    sendfile *worker=new sendfile;    //创建在此线程中的任务函数，干两件事
    worker->moveToThread(t);
    connect(this,&MainWindow::startconnect,worker,&sendfile::connectserver);
    connect(worker,&sendfile::connectOK,this,[=]()
    {
//        QMessageBox::information(this,"连接服务器","成功连接服务器");
          QMessageBox::information(this,"Connect to Server","success to connect to Server");
    });
    connect(worker,&sendfile::disconnectOK,this,[=]()
    {
        //资源释放
        t->quit();
        t->wait();
        worker->deleteLater();
        t->deleteLater();
    });
    connect(this,&MainWindow::sendfilepath,worker,&sendfile::SENDFILE);
    connect(worker,&sendfile::progress,ui->progressBar,&QProgressBar::setValue);

    t->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectpush_clicked()
{ 
    QString IP=ui->IPline->text();
    unsigned short port=ui->PORTline->text().toUShort();
    emit startconnect(IP,port);
}

void MainWindow::on_selectFilepush_clicked()
{
    QString path=QFileDialog::getOpenFileName();
    if(path.isEmpty())
    {
//        QMessageBox::warning(this,"打开文件：","选择的文件路径不能为空");
        QMessageBox::warning(this,"Open File","File path should not be NULL");
        return;
    }
    ui->Fileline->setText(path);
}


void MainWindow::on_sendButton_clicked()
{
    emit sendfilepath(ui->Fileline->text());
}

