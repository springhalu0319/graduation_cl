#include <QApplication>
#include <QSplashScreen>
#include <QIcon>
#include <QTextCodec>
#include <QTranslator>
#include <QObject>

#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(qtrc);
    app.setStartDragDistance(30);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")) ;
    app.setFont(QFont("simsun", 10));
    QTranslator translator( 0 );
    translator.load("M_zh_CN", ":/new/content/i18n/" );
    app.installTranslator( &translator );
    QTranslator translator1( 0 );
    translator1.load("MP_zh_CN", ":/new/content/i18n/" );
    app.installTranslator( &translator1 );
    QTranslator translator2( 0 );
    translator2.load("CP_zh_CN", ":/new/content/i18n/" );
    app.installTranslator( &translator2 );

    // Splash screen
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5)
    QPixmap pixmap(contentPath + "content/images/splash.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
#endif

    MainWidget mainWidget;
    mainWidget.setWindowIcon(QIcon(":/new/laola.ico"));
    mainWidget.setWindowTitle(QObject::tr("5 in a row"));
    mainWidget.show();

#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5)
    splash.finish(&mainWidget);
#endif

    return app.exec();
}
