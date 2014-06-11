/********************************************************************************
** Form generated from reading UI file 'gameStatus.ui'
**
** Created: Fri Apr 15 15:44:20 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESTATUS_H
#define UI_GAMESTATUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameStatusClass
{
public:
    QLabel *gameStatus_client_LB;
    QFrame *line;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *addr_me_client_LE;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *color_me_client_LE;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *record_me_client_LE;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *addr_rivar_client_LE;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *color_rivar_client_LE;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *record_rivar_client_LE;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *chatLog_client_TE;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *sendwords_client_LE;
    QPushButton *send_client_BTN;
    QHBoxLayout *horizontalLayout;
    QPushButton *undo_client_BTN;
    QPushButton *lose_client_BTN;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *gameReady_client_BTN;
    QPushButton *quit_client_BTN;

    void setupUi(QDialog *GameStatusClass)
    {
        if (GameStatusClass->objectName().isEmpty())
            GameStatusClass->setObjectName(QString::fromUtf8("GameStatusClass"));
        GameStatusClass->resize(882, 673);
        GameStatusClass->setMinimumSize(QSize(882, 673));
        GameStatusClass->setMaximumSize(QSize(925, 673));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        GameStatusClass->setPalette(palette);
        GameStatusClass->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Client/Resources/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        GameStatusClass->setWindowIcon(icon);
        gameStatus_client_LB = new QLabel(GameStatusClass);
        gameStatus_client_LB->setObjectName(QString::fromUtf8("gameStatus_client_LB"));
        gameStatus_client_LB->setGeometry(QRect(10, 640, 631, 31));
        gameStatus_client_LB->setStyleSheet(QString::fromUtf8(""));
        gameStatus_client_LB->setFrameShape(QFrame::NoFrame);
        line = new QFrame(GameStatusClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 640, 640, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(GameStatusClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(640, 10, 241, 661));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        addr_me_client_LE = new QLineEdit(groupBox);
        addr_me_client_LE->setObjectName(QString::fromUtf8("addr_me_client_LE"));
        addr_me_client_LE->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        addr_me_client_LE->setReadOnly(true);

        horizontalLayout_2->addWidget(addr_me_client_LE);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        color_me_client_LE = new QLineEdit(groupBox);
        color_me_client_LE->setObjectName(QString::fromUtf8("color_me_client_LE"));
        color_me_client_LE->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        color_me_client_LE->setReadOnly(true);

        horizontalLayout_8->addWidget(color_me_client_LE);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        record_me_client_LE = new QLineEdit(groupBox);
        record_me_client_LE->setObjectName(QString::fromUtf8("record_me_client_LE"));
        record_me_client_LE->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        record_me_client_LE->setReadOnly(true);

        horizontalLayout_3->addWidget(record_me_client_LE);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        addr_rivar_client_LE = new QLineEdit(groupBox_2);
        addr_rivar_client_LE->setObjectName(QString::fromUtf8("addr_rivar_client_LE"));
        addr_rivar_client_LE->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        addr_rivar_client_LE->setReadOnly(true);

        horizontalLayout_5->addWidget(addr_rivar_client_LE);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        color_rivar_client_LE = new QLineEdit(groupBox_2);
        color_rivar_client_LE->setObjectName(QString::fromUtf8("color_rivar_client_LE"));
        color_rivar_client_LE->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        color_rivar_client_LE->setReadOnly(true);

        horizontalLayout_9->addWidget(color_rivar_client_LE);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        record_rivar_client_LE = new QLineEdit(groupBox_2);
        record_rivar_client_LE->setObjectName(QString::fromUtf8("record_rivar_client_LE"));
        record_rivar_client_LE->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        record_rivar_client_LE->setReadOnly(true);

        horizontalLayout_6->addWidget(record_rivar_client_LE);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        chatLog_client_TE = new QTextEdit(groupBox_3);
        chatLog_client_TE->setObjectName(QString::fromUtf8("chatLog_client_TE"));
        chatLog_client_TE->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        chatLog_client_TE->setReadOnly(true);

        verticalLayout_3->addWidget(chatLog_client_TE);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        sendwords_client_LE = new QLineEdit(groupBox_3);
        sendwords_client_LE->setObjectName(QString::fromUtf8("sendwords_client_LE"));
        sendwords_client_LE->setEnabled(true);

        horizontalLayout_7->addWidget(sendwords_client_LE);

        send_client_BTN = new QPushButton(groupBox_3);
        send_client_BTN->setObjectName(QString::fromUtf8("send_client_BTN"));
        send_client_BTN->setEnabled(false);
        send_client_BTN->setDefault(true);

        horizontalLayout_7->addWidget(send_client_BTN);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(groupBox_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        undo_client_BTN = new QPushButton(layoutWidget);
        undo_client_BTN->setObjectName(QString::fromUtf8("undo_client_BTN"));
        undo_client_BTN->setEnabled(false);

        horizontalLayout->addWidget(undo_client_BTN);

        lose_client_BTN = new QPushButton(layoutWidget);
        lose_client_BTN->setObjectName(QString::fromUtf8("lose_client_BTN"));
        lose_client_BTN->setEnabled(false);

        horizontalLayout->addWidget(lose_client_BTN);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gameReady_client_BTN = new QPushButton(layoutWidget);
        gameReady_client_BTN->setObjectName(QString::fromUtf8("gameReady_client_BTN"));

        horizontalLayout_4->addWidget(gameReady_client_BTN);

        quit_client_BTN = new QPushButton(layoutWidget);
        quit_client_BTN->setObjectName(QString::fromUtf8("quit_client_BTN"));

        horizontalLayout_4->addWidget(quit_client_BTN);


        verticalLayout_4->addLayout(horizontalLayout_4);

        QWidget::setTabOrder(send_client_BTN, sendwords_client_LE);
        QWidget::setTabOrder(sendwords_client_LE, gameReady_client_BTN);
        QWidget::setTabOrder(gameReady_client_BTN, undo_client_BTN);
        QWidget::setTabOrder(undo_client_BTN, lose_client_BTN);
        QWidget::setTabOrder(lose_client_BTN, quit_client_BTN);
        QWidget::setTabOrder(quit_client_BTN, addr_me_client_LE);
        QWidget::setTabOrder(addr_me_client_LE, record_me_client_LE);
        QWidget::setTabOrder(record_me_client_LE, addr_rivar_client_LE);
        QWidget::setTabOrder(addr_rivar_client_LE, record_rivar_client_LE);
        QWidget::setTabOrder(record_rivar_client_LE, chatLog_client_TE);

        retranslateUi(GameStatusClass);

        QMetaObject::connectSlotsByName(GameStatusClass);
    } // setupUi

    void retranslateUi(QDialog *GameStatusClass)
    {
        GameStatusClass->setWindowTitle(QApplication::translate("GameStatusClass", "\347\275\221\347\273\234\344\272\224\345\255\220\346\243\213 - \346\270\270\346\210\217\344\270\255....", 0, QApplication::UnicodeUTF8));
        gameStatus_client_LB->setText(QString());
        groupBox->setTitle(QApplication::translate("GameStatusClass", "\350\207\252\345\267\261", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GameStatusClass", "\346\230\265\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("GameStatusClass", "\351\242\234\350\211\262:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GameStatusClass", "\346\210\230\347\273\251:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("GameStatusClass", "\345\257\271\346\211\213", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GameStatusClass", "\346\230\265\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("GameStatusClass", "\351\242\234\350\211\262:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("GameStatusClass", "\346\210\230\347\273\251:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("GameStatusClass", "\350\201\212\345\244\251", 0, QApplication::UnicodeUTF8));
        send_client_BTN->setText(QApplication::translate("GameStatusClass", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        undo_client_BTN->setText(QApplication::translate("GameStatusClass", "\346\202\224\346\243\213", 0, QApplication::UnicodeUTF8));
        lose_client_BTN->setText(QApplication::translate("GameStatusClass", "\350\256\244\350\276\223", 0, QApplication::UnicodeUTF8));
        gameReady_client_BTN->setText(QApplication::translate("GameStatusClass", "\345\207\206\345\244\207", 0, QApplication::UnicodeUTF8));
        quit_client_BTN->setText(QApplication::translate("GameStatusClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameStatusClass: public Ui_GameStatusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESTATUS_H
