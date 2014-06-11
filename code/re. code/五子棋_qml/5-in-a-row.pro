CONFIG -= app_bundle

SOURCES = main.cpp \
    mainwidget.cpp \
    gamedata.cpp

QT += script \
    declarative

# This is needed for Maemo5 to recognize minimization of the application window
maemo5 {
    QT += dbus
}

contains(QT_CONFIG, opengles2)|contains(QT_CONFIG, opengl):QT += opengl
sources.files += $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    5-in-a-row.pro

OTHER_FILES += 5-in-a-row.desktop

TRANSLATION += content/i18n/CP_zh_CN.ts \
    content/i18n/M_zh_CN.ts \
    content/i18n/MP_zh_CN.ts

HEADERS += tile.h \
    mainwidget.h \
    gamedata.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/bin
    } else {
        target.path = /usr/local/bin
    }
    INSTALLS += target
}

unix:!symbian {
    desktopfile.files = $${TARGET}.desktop
    maemo5 {
        desktopfile.path = /usr/share/applications/hildon
    } else {
        desktopfile.path = /usr/share/applications
    }
    INSTALLS += desktopfile
}

RESOURCES += qtrc.qrc

