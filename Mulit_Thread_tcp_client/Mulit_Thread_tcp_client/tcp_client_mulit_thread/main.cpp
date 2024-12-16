#include "mainwindow.h"
#include <QApplication>
#include <QFont>
#include <QTextCodec>

//#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
//#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置中文字体
    a.setFont(QFont("Microsoft Yahei", 9));

    //设置中文编码
    #if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
    #if _MSC_VER
        QTextCodec *codec = QTextCodec::codecForName("gbk");
    #else
        QTextCodec *codec = QTextCodec::codecForName("utf-8");
    #endif
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
    #elif (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
        QTextCodec *codec = QTextCodec::codecForName("utf-8");
        QTextCodec::setCodecForLocale(codec);
    #else
        //Qt6不需要
    #endif
    MainWindow w;
    w.show();

    return a.exec();
}
