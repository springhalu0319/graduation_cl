/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created: Fri Apr 15 10:40:52 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

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

class Ui_ServerClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *startServer_server_BTN;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *connLimit_server_LE;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *connPort_server_LE;

    void setupUi(QMainWindow *ServerClass)
    {
        if (ServerClass->objectName().isEmpty())
            ServerClass->setObjectName(QString::fromUtf8("ServerClass"));
        ServerClass->resize(445, 314);
        ServerClass->setMinimumSize(QSize(445, 314));
        ServerClass->setMaximumSize(QSize(445, 314));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ServerClass->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Server/Resources/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ServerClass->setWindowIcon(icon);
        centralWidget = new QWidget(ServerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 321, 61));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        startServer_server_BTN = new QPushButton(centralWidget);
        startServer_server_BTN->setObjectName(QString::fromUtf8("startServer_server_BTN"));
        startServer_server_BTN->setGeometry(QRect(170, 250, 91, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(91, 190, 261, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(11);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        connLimit_server_LE = new QLineEdit(layoutWidget);
        connLimit_server_LE->setObjectName(QString::fromUtf8("connLimit_server_LE"));
        connLimit_server_LE->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(connLimit_server_LE);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(91, 130, 261, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        connPort_server_LE = new QLineEdit(layoutWidget1);
        connPort_server_LE->setObjectName(QString::fromUtf8("connPort_server_LE"));
        connPort_server_LE->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(connPort_server_LE);

        ServerClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(connPort_server_LE, connLimit_server_LE);
        QWidget::setTabOrder(connLimit_server_LE, startServer_server_BTN);

        retranslateUi(ServerClass);

        QMetaObject::connectSlotsByName(ServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *ServerClass)
    {
        ServerClass->setWindowTitle(QApplication::translate("ServerClass", "\347\275\221\347\273\234\344\272\224\345\255\220\346\243\213 - \346\234\215\345\212\241\347\253\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ServerClass", "\346\254\242\350\277\216\344\275\277\347\224\250\347\275\221\347\273\234\344\272\224\345\255\220\346\243\213", 0, QApplication::UnicodeUTF8));
        startServer_server_BTN->setText(QApplication::translate("ServerClass", "\345\274\200\345\220\257\346\234\215\345\212\241", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ServerClass", "\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245\344\270\212\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        connLimit_server_LE->setText(QApplication::translate("ServerClass", "50", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ServerClass", "\346\234\215\345\212\241\345\231\250\346\270\270\346\210\217\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        connPort_server_LE->setText(QApplication::translate("ServerClass", "45454", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerClass: public Ui_ServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
