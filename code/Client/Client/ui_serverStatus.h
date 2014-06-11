/********************************************************************************
** Form generated from reading UI file 'serverStatus.ui'
**
** Created: Wed Apr 13 17:19:04 2011
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
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerStatusClass
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *clientStatus_client_TBW;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *create_client_BTN;
    QFrame *line;
    QPushButton *quit_client_BTN;

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
        icon.addFile(QString::fromUtf8(":/Client/Resources/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ServerStatusClass->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(ServerStatusClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clientStatus_client_TBW = new QTableWidget(ServerStatusClass);
        if (clientStatus_client_TBW->columnCount() < 3)
            clientStatus_client_TBW->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        clientStatus_client_TBW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        clientStatus_client_TBW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        clientStatus_client_TBW->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        clientStatus_client_TBW->setObjectName(QString::fromUtf8("clientStatus_client_TBW"));
        clientStatus_client_TBW->setEditTriggers(QAbstractItemView::NoEditTriggers);
        clientStatus_client_TBW->setSelectionMode(QAbstractItemView::SingleSelection);
        clientStatus_client_TBW->setSelectionBehavior(QAbstractItemView::SelectRows);
        clientStatus_client_TBW->setGridStyle(Qt::SolidLine);
        clientStatus_client_TBW->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(clientStatus_client_TBW);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        create_client_BTN = new QPushButton(ServerStatusClass);
        create_client_BTN->setObjectName(QString::fromUtf8("create_client_BTN"));

        horizontalLayout->addWidget(create_client_BTN);

        line = new QFrame(ServerStatusClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        quit_client_BTN = new QPushButton(ServerStatusClass);
        quit_client_BTN->setObjectName(QString::fromUtf8("quit_client_BTN"));

        horizontalLayout->addWidget(quit_client_BTN);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(create_client_BTN, quit_client_BTN);
        QWidget::setTabOrder(quit_client_BTN, clientStatus_client_TBW);

        retranslateUi(ServerStatusClass);

        QMetaObject::connectSlotsByName(ServerStatusClass);
    } // setupUi

    void retranslateUi(QDialog *ServerStatusClass)
    {
        ServerStatusClass->setWindowTitle(QApplication::translate("ServerStatusClass", "\347\275\221\347\273\234\344\272\224\345\255\220\346\243\213 - \345\212\240\345\205\245\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = clientStatus_client_TBW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ServerStatusClass", "\344\270\273\346\234\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = clientStatus_client_TBW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ServerStatusClass", "\345\257\271\346\211\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = clientStatus_client_TBW->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ServerStatusClass", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        create_client_BTN->setText(QApplication::translate("ServerStatusClass", "\345\273\272\347\253\213\344\270\273\346\234\272", 0, QApplication::UnicodeUTF8));
        quit_client_BTN->setText(QApplication::translate("ServerStatusClass", "\351\200\200\345\207\272\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerStatusClass: public Ui_ServerStatusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERSTATUS_H
