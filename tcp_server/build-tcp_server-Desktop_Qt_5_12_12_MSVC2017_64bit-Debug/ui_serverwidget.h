/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonClose;
    QPushButton *ButtonSend;
    QTextEdit *textEditwrite;
    QTextEdit *textEditread;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(600, 600);
        gridLayout = new QGridLayout(ServerWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(407, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        ButtonClose = new QPushButton(ServerWidget);
        ButtonClose->setObjectName(QString::fromUtf8("ButtonClose"));

        gridLayout->addWidget(ButtonClose, 2, 2, 1, 1);

        ButtonSend = new QPushButton(ServerWidget);
        ButtonSend->setObjectName(QString::fromUtf8("ButtonSend"));

        gridLayout->addWidget(ButtonSend, 2, 0, 1, 1);

        textEditwrite = new QTextEdit(ServerWidget);
        textEditwrite->setObjectName(QString::fromUtf8("textEditwrite"));

        gridLayout->addWidget(textEditwrite, 1, 0, 1, 3);

        textEditread = new QTextEdit(ServerWidget);
        textEditread->setObjectName(QString::fromUtf8("textEditread"));
        textEditread->setReadOnly(true);

        gridLayout->addWidget(textEditread, 0, 0, 1, 3);


        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QApplication::translate("ServerWidget", "ServerWidget", nullptr));
        ButtonClose->setText(QApplication::translate("ServerWidget", "close", nullptr));
        ButtonSend->setText(QApplication::translate("ServerWidget", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
