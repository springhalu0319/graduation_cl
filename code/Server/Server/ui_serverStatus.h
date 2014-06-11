/********************************************************************************
** Form generated from reading UI file 'serverStatus.ui'
**
** Created: Wed Apr 13 15:24:51 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERSTATUS_H
#define UI_SERVERSTATUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerStatusClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *clientStatus_server_TBW;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *curConnCount_server_LE;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeServer_server_BTN;

    void setupUi(QDialog *ServerStatusClass)
    {
        if (ServerStatusClass->objectName().isEmpty())
            ServerStatusClass->setObjectName(QString::fromUtf8("ServerStatusClass"));
        ServerStatusClass->resize(433, 288);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ServerStatusClass->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Server/Resources/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ServerStatusClass->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(ServerStatusClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clientStatus_server_TBW = new QTableWidget(ServerStatusClass);
        if (clientStatus_server_TBW->columnCount() < 3)
            clientStatus_server_TBW->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        clientStatus_server_TBW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        clientStatus_server_TBW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        clientStatus_server_TBW->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        clientStatus_server_TBW->setObjectName(QString::fromUtf8("clientStatus_server_TBW"));
        clientStatus_server_TBW->setEditTriggers(QAbstractItemView::NoEditTriggers);
        clientStatus_server_TBW->setSelectionMode(QAbstractItemView::SingleSelection);
        clientStatus_server_TBW->setSelectionBehavior(QAbstractItemView::SelectRows);
        clientStatus_server_TBW->setGridStyle(Qt::SolidLine);
        clientStatus_server_TBW->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(clientStatus_server_TBW);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(ServerStatusClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        curConnCount_server_LE = new QLineEdit(ServerStatusClass);
        curConnCount_server_LE->setObjectName(QString::fromUtf8("curConnCount_server_LE"));
        curConnCount_server_LE->setEnabled(false);

        horizontalLayout->addWidget(curConnCount_server_LE);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeServer_server_BTN = new QPushButton(ServerStatusClass);
        closeServer_server_BTN->setObjectName(QString::fromUtf8("closeServer_server_BTN"));

        horizontalLayout->addWidget(closeServer_server_BTN);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(closeServer_server_BTN, clientStatus_server_TBW);
        QWidget::setTabOrder(clientStatus_server_TBW, curConnCount_server_LE);

        retranslateUi(ServerStatusClass);

        QMetaObject::connectSlotsByName(ServerStatusClass);
    } // setupUi

    void retranslateUi(QDialog *ServerStatusClass)
    {
        ServerStatusClass->setWindowTitle(QApplication::translate("ServerStatusClass", "\347\275\221\347\273\234\344\272\224\345\255\220\346\243\213 - \346\234\215\345\212\241\347\253\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = clientStatus_server_TBW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ServerStatusClass", "\344\270\273\346\234\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = clientStatus_server_TBW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ServerStatusClass", "\345\257\271\346\211\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = clientStatus_server_TBW->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ServerStatusClass", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ServerStatusClass", "\345\275\223\345\211\215\347\216\251\345\256\266\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        closeServer_server_BTN->setText(QApplication::translate("ServerStatusClass", "\345\205\263\351\227\255\346\234\215\345\212\241", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerStatusClass: public Ui_ServerStatusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERSTATUS_H
