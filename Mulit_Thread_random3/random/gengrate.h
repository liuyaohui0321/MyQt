#ifndef GENGRATE_H
#define GENGRATE_H

#include <QThread>
#include <QVector>
#include <QDebug>
#include <QRunnable>

//生成随机数
class gengrate : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit gengrate(QObject *parent = nullptr);
    void rev_num(int num);   
    void run()     override;
signals:
    void sendarray(QVector<int> num);

private:
    int m_num;
};

#endif // GENGRATE_H

class BubbleSort :public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void rev_array(QVector<int> list);
    void run()     override;
signals:
    void finish(QVector<int> list);
private:
    QVector<int> m_list;
};

class QuickSort : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void rev_array(QVector<int> list);
    void run()     override;
signals:
    void finish(QVector<int> num);
private:
    void quicksort(QVector<int> &list,int l,int r);
    QVector<int> m_list;
};
