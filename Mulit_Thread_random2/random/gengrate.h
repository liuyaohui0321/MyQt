#ifndef GENGRATE_H
#define GENGRATE_H

#include <QThread>
#include <QVector>
#include <QDebug>
#include <QObject>
//生成随机数
class gengrate : public QObject
{
    Q_OBJECT
public:
    explicit gengrate(QObject *parent = nullptr);
    void working(int num);
signals:
    void sendarray(QVector<int> num);
};

#endif // GENGRATE_H

class BubbleSort : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void working(QVector<int> list);
signals:
    void finish(QVector<int> list);
};

class QuickSort : public QObject
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void working(QVector<int> list);
signals:
    void finish(QVector<int> num);
private:
    void quicksort(QVector<int> &list,int l,int r);

};
