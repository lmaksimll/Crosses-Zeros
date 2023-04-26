QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bot.cpp \
    field.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    prnt_cage.cpp \
    prnt_count.cpp \
    prnt_symbol.cpp \
    style_cage.cpp

HEADERS += \
    bot.h \
    field.h \
    mainwindow.h \
    player.h \
    prnt_cage.h \
    prnt_count.h \
    prnt_symbol.h \
    style_cage.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourses.qrc
