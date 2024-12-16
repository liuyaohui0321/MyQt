#ifndef GENGRATE_H
#define GENGRATE_H

#include <QThread>
#include <QVector>
#include <QDebug>

//生成随机数
class gengrate : public QThread
{
    Q_OBJECT
public:
    explicit gengrate(QObject *parent = nullptr);
    void rev_num(int num);
signals:
    void sendarray(QVector<int> num);
protected:
    void run()     override;
private:
    int m_num;
};

#endif // GENGRATE_H

class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void rev_array(QVector<int> list);
signals:
    void finish(QVector<int> list);
protected:
    void run()     override;
private:
    QVector<int> m_list;
};

class QuickSort : public QThread
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void rev_array(QVector<int> list);
signals:
    void finish(QVector<int> num);
protected:
    void run()     override;
private:
    void quicksort(QVector<int> &list,int l,int r);
    QVector<int> m_list;
};
