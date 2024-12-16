#ifndef RECVFILE_H
#define RECVFILE_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QFile>
#include <QByteArray>

class RecvFile : public QThread
{
    Q_OBJECT
public:
    explicit RecvFile(QTcpSocket *tcp,QObject *parent = nullptr);

protected:
    void run() override;
signals:
    void over();
private:
    QTcpSocket *m_tcp;

};

#endif // RECVFILE_H
