#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QFileInfo>

class sendfile : public QObject
{
    Q_OBJECT
public:
    explicit sendfile(QObject *parent = nullptr);

    //连接服务器
    void connectserver(QString ip,unsigned short port);

    //发送文件
    void SENDFILE(QString path);

signals:
    void connectOK();
    void disconnectOK();
    void progress(int num);

public slots:

private:
    QTcpSocket *m_Tcpsocket;
};

#endif // SENDFILE_H
