#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton;
    button->show();
    button->setParent(this);
    button->setText("磁盘管理");
    button->move(0,0);
    button->setFixedSize(100,30);

    QPushButton *button2 = new QPushButton("帮助",this);
    button2->move(100,0);
    button2->setFixedSize(100,30);

    QPushButton *button3 = new QPushButton("关闭",this);
    //      button3->setFixedSize(200,50);
    button3->move(500,0);

    this->resize(600,400);
    this->setWindowTitle("存储显控软件");

    connect(button3,&QPushButton::released,this,&Widget::close);

    this->teacher=new Teacher;
    this->student=new Student;
    //    connect(this->teacher,&teacher::hungry,this->Student,&Student::treat);
    connect(button2,&QPushButton::clicked,this->student,&Student::treat);
}

Widget::~Widget()
{
}

