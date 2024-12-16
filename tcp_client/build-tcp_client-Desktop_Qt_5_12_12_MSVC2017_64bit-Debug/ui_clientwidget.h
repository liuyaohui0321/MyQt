/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPORT;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;
    QPushButton *pushButtonConnect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(600, 600);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClientWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(ClientWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 1);

        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPORT = new QLineEdit(ClientWidget);
        lineEditPORT->setObjectName(QString::fromUtf8("lineEditPORT"));

        gridLayout->addWidget(lineEditPORT, 1, 1, 1, 1);

        textEditRead = new QTextEdit(ClientWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 2, 0, 1, 3);

        textEditWrite = new QTextEdit(ClientWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 3, 0, 1, 3);

        pushButtonSend = new QPushButton(ClientWidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(407, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 1);

        pushButtonClose = new QPushButton(ClientWidget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 4, 2, 1, 1);

        pushButtonConnect = new QPushButton(ClientWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        gridLayout->addWidget(pushButtonConnect, 0, 2, 2, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "ClientWidget", nullptr));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        lineEditIP->setText(QString());
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        pushButtonSend->setText(QApplication::translate("ClientWidget", "send", nullptr));
        pushButtonClose->setText(QApplication::translate("ClientWidget", "close", nullptr));
        pushButtonConnect->setText(QApplication::translate("ClientWidget", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
