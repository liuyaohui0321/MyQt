#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("存储显控软件");




    QPushButton btn1;
    btn1.setText("磁盘管理");
    btn1.setParent(&w);
    btn1.resize(100,50);
    btn1.show();

    QPushButton btn2("帮助",&w);
    btn2.move(100,0);
    btn2.resize(100,50);
    btn2.setParent(&w);
    btn2.show();

    QPushButton *btn3 =new(QPushButton);

    connect(btn3,&QPushButton::clicked,this,&MainWindow::close);
    return a.exec();
}
