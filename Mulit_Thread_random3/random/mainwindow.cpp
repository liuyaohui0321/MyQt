#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gengrate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1.创建任务对象
    gengrate *Gen=new gengrate;
    BubbleSort *bubbleSort=new BubbleSort;
    QuickSort *quickSort=new QuickSort;

    connect(this,&MainWindow::Starting,Gen,&gengrate::rev_num);
    //2.启动子线程
    connect(ui->startpushButton,&QPushButton::clicked,this,[=]()
    {
        emit Starting(10000);
        QThreadPool::globalInstance()->start(Gen);
    }
    );
    //接收随机数线程发送过来的随机数
    connect(Gen,&gengrate::sendarray,bubbleSort,&BubbleSort::rev_array);
    connect(Gen,&gengrate::sendarray,quickSort,&QuickSort::rev_array);
    //3.接收子线程发送过来的随机数
    connect(Gen,&gengrate::sendarray,this,[=](QVector<int> list)
    {
        for(int i=0;i<list.size();++i)
        {
            ui->randomlist->addItem(QString::number(list.at(i)));
        }
//        //接收随机数线程发送过来的随机数 //不能放在这里，要不然冒泡、快速进不到槽函数
//        connect(Gen,&gengrate::sendarray,bubbleSort,&BubbleSort::rev_array);
//        connect(Gen,&gengrate::sendarray,quickSort,&QuickSort::rev_array);
        QThreadPool::globalInstance()->start(bubbleSort);
        QThreadPool::globalInstance()->start(quickSort);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
