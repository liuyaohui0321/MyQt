#include "gengrate.h"
#include <QElapsedTimer>

gengrate::gengrate(QObject *parent) : QObject(parent),QRunnable()
{
     setAutoDelete(true);
}

void gengrate::rev_num(int num)
{
    m_num=num;
}

void gengrate::run()
{
    qDebug()<<"生成随机数线程的线程地址"<<QThread::currentThread();
    QVector<int> list;
    QElapsedTimer time;
    int milsec;
    time.start();
    for(int i=0;i<m_num;++i)
    {
        list.push_back(qrand()%10000);
    }
    milsec =time.elapsed();
    qDebug()<<"生成"<<m_num<<"个随机数总用时："<<milsec<<"毫秒";
    emit sendarray(list);
}

BubbleSort::BubbleSort(QObject *parent): QObject(parent),QRunnable()
{
    setAutoDelete(true);
}

void BubbleSort::rev_array(QVector<int> list)
{
    m_list=list;
}

void BubbleSort::run()
{
    int temp=0;
    qDebug()<<"冒泡排序线程的线程地址"<<QThread::currentThread();
    QElapsedTimer time;
    int milsec;
    time.start();
    for(int i=0;i<m_list.size();++i)
    {
        for(int j=0;j<m_list.size()-i-1;++j)
        {
            if(m_list[j]> m_list[j+1])
            {
                temp = m_list[j];
                m_list[j] = m_list[j+1];
                m_list[j+1]= temp;
            }
        }
    }
    milsec =time.elapsed();
    qDebug()<<"冒泡排序总用时："<<milsec<<"毫秒";
    emit finish(m_list);
}

QuickSort::QuickSort(QObject *parent): QObject(parent),QRunnable()
{
    setAutoDelete(true);
}

void QuickSort::rev_array(QVector<int> list)
{
    m_list=list;
}

void QuickSort::run()
{
    int temp=0;
    qDebug()<<"快速排序线程的线程地址"<<QThread::currentThread();
    QElapsedTimer time;
    int milsec;
    time.start();
    quicksort(m_list,0,m_list.size()-1);
    milsec =time.elapsed();
    qDebug()<<"快速排序总用时："<<milsec<<"毫秒";
    emit finish(m_list);
}

void QuickSort::quicksort(QVector<int> &list, int l, int r)
{
    if (l<r)
    {
        int i=l,j=r;
        // 拿出第一个元素，保存到x中,第一个位置成为一个坑
        int x= list[l];
        while(i< j)
        {
            //从右向左找小于x的数
            while(i < j&& list[j]>= x)
            {
                //左移，直到遇到小于等于x的数
                j--;
            }
            if(i< j)
            {
                //将右侧找到的小于x的元素放入左侧坑中，右侧出现一个坑
                //左侧元素索引后移
                list[i++]= list[j];
            }
            // 从左向右找大于等于x的数
            while(i<j&& list[i]< x)
            {
                //右移，直到遇到大于x的数
                i++;
            }
            if(i< j)
            {
                //将左侧找到的元素放入右侧坑中，左侧出现一个坑
                //右侧元素索引向前移动
                list[j--]= list[i];
            }
       }
        //此时 i=j,将保存在x中的数填入坑中
        list[i]= x;
        quicksort(list,l,i-1);// 递归调用
        quicksort(list,i+1,r);
    }
}
