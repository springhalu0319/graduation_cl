/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created: Thu Apr 14 10:16:46 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientClass
{
public:
    QWidget *centralWidget;
    QPushButton *conn_client_BTN;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *serverAddr_client_LE;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *serverPort_client_LE;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *nickName_client_LE;

    void setupUi(QMainWindow *ClientClass)
    {
        if (ClientClass->objectName().isEmpty())
            ClientClass->setObjectName(QString::fromUtf8("ClientClass"));
        ClientClass->resize(445, 366);
        ClientClass->setMinimumSize(QSize(445, 366));
        ClientClass->setMaximumSize(QSize(445, 366));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ClientClass->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Client/Resources/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ClientClass->setWindowIcon(icon);
        centralWidget = new QWidget(ClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        conn_client_BTN = new QPushButton(centralWidget);
        conn_client_BTN->setObjectName(QString::fromUtf8("conn_client_BTN"));
        conn_client_BTN->setGeometry(QRect(170, 300, 91, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 40, 321, 61));
        QFont font;
        font.setPointSize(26);
        label_3->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 180, 261, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        serverAddr_client_LE = new QLineEdit(layoutWidget);
        serverAddr_client_LE->setObjectName(QString::fromUtf8("serverAddr_client_LE"));
        serverAddr_client_LE->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(serverAddr_client_LE);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 240, 261, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        serverPort_client_LE = new QLineEdit(layoutWidget1);
        serverPort_client_LE->setObjectName(QString::fromUtf8("serverPort_client_LE"));
        serverPort_client_LE->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(serverPort_client_LE);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 120, 261, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        nickName_client_LE = new QLineEdit(layoutWidget_2);
        nickName_client_LE->setObjectName(QString::fromUtf8("nickName_client_LE"));
        nickName_client_LE->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(nickName_client_LE);

        ClientClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(nickName_client_LE, serverAddr_client_LE);
        QWidget::setTabOrder(serverAddr_client_LE, serverPort_client_LE);
        QWidget::setTabOrder(serverPort_client_LE, conn_client_BTN);

        retranslateUi(ClientClass);

        QMetaObject::connectSlotsByName(ClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClientClass)
    {
        ClientClass->setWindowTitle(QApplication::translate("ClientClass", "\347\275\221\347\273\234\344\272\224\345\255\220\346\243\213 - \345\256\242\346\210\267\347\253\257", 0, QApplication::UnicodeUTF8));
        conn_client_BTN->setText(QApplication::translate("ClientClass", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ClientClass", "\346\254\242\350\277\216\344\275\277\347\224\250\347\275\221\347\273\234\344\272\224\345\255\220\346\243\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ClientClass", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        serverAddr_client_LE->setText(QApplication::translate("ClientClass", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClientClass", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        serverPort_client_LE->setText(QApplication::translate("ClientClass", "45454", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ClientClass", "\347\216\251\345\256\266\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        nickName_client_LE->setText(QApplication::translate("ClientClass", "anonymous", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientClass: public Ui_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
