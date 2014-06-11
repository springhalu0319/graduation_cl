/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created: Wed Jul 7 01:11:37 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *line;
    QRadioButton *circle;
    QRadioButton *rectangle;
    QRadioButton *ellipse;
    QGroupBox *groupBox_conn;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *hostName;
    QPushButton *login;
    QPushButton *logout;

    void setupUi(QMainWindow *clientClass)
    {
        if (clientClass->objectName().isEmpty())
            clientClass->setObjectName(QString::fromUtf8("clientClass"));
        clientClass->resize(600, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/client/Easel2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        clientClass->setWindowIcon(icon);
        centralWidget = new QWidget(clientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 316, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        line = new QRadioButton(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setChecked(true);

        horizontalLayout_2->addWidget(line);

        circle = new QRadioButton(groupBox);
        circle->setObjectName(QString::fromUtf8("circle"));
        circle->setChecked(false);

        horizontalLayout_2->addWidget(circle);

        rectangle = new QRadioButton(groupBox);
        rectangle->setObjectName(QString::fromUtf8("rectangle"));

        horizontalLayout_2->addWidget(rectangle);

        ellipse = new QRadioButton(groupBox);
        ellipse->setObjectName(QString::fromUtf8("ellipse"));

        horizontalLayout_2->addWidget(ellipse);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_conn = new QGroupBox(centralWidget);
        groupBox_conn->setObjectName(QString::fromUtf8("groupBox_conn"));
        horizontalLayout = new QHBoxLayout(groupBox_conn);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_conn);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        hostName = new QLineEdit(groupBox_conn);
        hostName->setObjectName(QString::fromUtf8("hostName"));
        hostName->setContextMenuPolicy(Qt::DefaultContextMenu);
        hostName->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(hostName);

        login = new QPushButton(groupBox_conn);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout->addWidget(login);

        logout = new QPushButton(groupBox_conn);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setEnabled(false);

        horizontalLayout->addWidget(logout);


        horizontalLayout_3->addWidget(groupBox_conn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        clientClass->setCentralWidget(centralWidget);

        retranslateUi(clientClass);

        QMetaObject::connectSlotsByName(clientClass);
    } // setupUi

    void retranslateUi(QMainWindow *clientClass)
    {
        clientClass->setWindowTitle(QApplication::translate("clientClass", "\345\205\261\344\272\253\347\231\275\346\235\277\345\256\242\346\210\267\347\253\257", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("clientClass", "\345\275\242\347\212\266", 0, QApplication::UnicodeUTF8));
        line->setText(QApplication::translate("clientClass", "\347\272\277", 0, QApplication::UnicodeUTF8));
        circle->setText(QApplication::translate("clientClass", "\345\234\206", 0, QApplication::UnicodeUTF8));
        rectangle->setText(QApplication::translate("clientClass", "\347\237\251\345\275\242", 0, QApplication::UnicodeUTF8));
        ellipse->setText(QApplication::translate("clientClass", "\346\244\255\345\234\206", 0, QApplication::UnicodeUTF8));
        groupBox_conn->setTitle(QApplication::translate("clientClass", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("clientClass", "\344\270\273\346\234\272IP\357\274\232", 0, QApplication::UnicodeUTF8));
        login->setText(QApplication::translate("clientClass", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        logout->setText(QApplication::translate("clientClass", "\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clientClass: public Ui_clientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
