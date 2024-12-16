#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setlistenButton_clicked();

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *m_TcpServer;  //服务器绑定套接字
    QTcpSocket *m_TcpSocket;  //通信套接字
    QLabel *m_status;
};
#endif // MAINWINDOW_H
