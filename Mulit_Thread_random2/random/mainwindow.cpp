#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gengrate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1.创建三个子线程
    QThread* t1= new QThread;//可以加(this)这样主线程父对象析构的时候，子对象也会析构（都是QObiect的类）
    QThread* t2= new QThread;//不加this的话，也可以利用槽函数来对线程释放
    QThread* t3= new QThread;

    //2.创建三个任务类对象
    gengrate *Gen=new gengrate;
    BubbleSort *bubbleSort=new BubbleSort;
    QuickSort *quickSort=new QuickSort;

    //3.将任务对象移动到子线程里
    Gen->moveToThread(t1);
    bubbleSort->moveToThread(t2);
    quickSort->moveToThread(t3);

    connect(this,&MainWindow::Starting,Gen,&gengrate::working);
    //2.启动子线程
    connect(ui->startpushButton,&QPushButton::clicked,this,[=]()
    {
        emit Starting(10000);
        t1->start();
    }
    );
    //接收随机数线程发送过来的随机数
    connect(Gen,&gengrate::sendarray,bubbleSort,&BubbleSort::working);
    connect(Gen,&gengrate::sendarray,quickSort,&QuickSort::working);
    //3.主线程接收子线程发送过来的随机数
    connect(Gen,&gengrate::sendarray,this,[=](QVector<int> list)
    {
        for(int i=0;i<list.size();++i)
        {
            ui->randomlist->addItem(QString::number(list.at(i)));
        }
        t2->start();
        t3->start();
    });

    //4.接收子线程发送过来的冒泡排序数
    connect(bubbleSort,&BubbleSort::finish,this,[=](QVector<int> list)
    {
        for(int i=0;i<list.size();++i)
        {
            ui->bubblelist->addItem(QString::number(list.at(i)));
        }
    });
    //5.接收子线程发送过来的快速排序数
    connect(quickSort,&QuickSort::finish,this,[=](QVector<int> list)
    {
        for(int i=0;i<list.size();++i)
        {
            ui->quicklist->addItem(QString::number(list.at(i)));
        }
    });
    //线程释放
    connect(this,&MainWindow::destroyed,this,[=]()
    {
        t1->quit()
        t1->wait();
        t1->deleteLater();// delete t1:

        t2->quit();
        t2->wait();
        t2->deleteLater();

        t3->quit();
        t3->wait();
        t3->deleteLater();
        Gen->deleteLater();
        bubbleSort->deleteLater();
        quickSort->deleteLater();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
