/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created: Sun Apr 10 14:21:48 2011
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
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *userList;
    QPushButton *startServer;
    QPushButton *stopServer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *userOP;

    void setupUi(QMainWindow *serverClass)
    {
        if (serverClass->objectName().isEmpty())
            serverClass->setObjectName(QString::fromUtf8("serverClass"));
        serverClass->resize(598, 375);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/server/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        serverClass->setWindowIcon(icon);
        centralWidget = new QWidget(serverClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(160, 16777215));

        verticalLayout->addWidget(label);

        userList = new QListWidget(centralWidget);
        userList->setObjectName(QString::fromUtf8("userList"));
        userList->setMaximumSize(QSize(160, 16777215));
        userList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(userList);

        startServer = new QPushButton(centralWidget);
        startServer->setObjectName(QString::fromUtf8("startServer"));
        startServer->setMaximumSize(QSize(160, 16777215));

        verticalLayout->addWidget(startServer);

        stopServer = new QPushButton(centralWidget);
        stopServer->setObjectName(QString::fromUtf8("stopServer"));
        stopServer->setEnabled(false);
        stopServer->setMaximumSize(QSize(160, 16777215));

        verticalLayout->addWidget(stopServer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        userOP = new QTextEdit(centralWidget);
        userOP->setObjectName(QString::fromUtf8("userOP"));
        userOP->setReadOnly(true);

        verticalLayout_2->addWidget(userOP);


        horizontalLayout->addLayout(verticalLayout_2);

        serverClass->setCentralWidget(centralWidget);

        retranslateUi(serverClass);

        QMetaObject::connectSlotsByName(serverClass);
    } // setupUi

    void retranslateUi(QMainWindow *serverClass)
    {
        serverClass->setWindowTitle(QApplication::translate("serverClass", "server", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("serverClass", "\347\224\250\346\210\267\345\210\227\350\241\250\357\274\232", 0, QApplication::UnicodeUTF8));
        startServer->setText(QApplication::translate("serverClass", "\345\220\257\345\212\250\346\234\215\345\212\241", 0, QApplication::UnicodeUTF8));
        stopServer->setText(QApplication::translate("serverClass", "\345\201\234\346\255\242\346\234\215\345\212\241", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("serverClass", "\347\224\250\346\210\267\346\223\215\344\275\234\344\277\241\346\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class serverClass: public Ui_serverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
