TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network
CONFIG += c++11

SOURCES += main.cpp \
    mainwindow.cpp \
    filedownloader.cpp \
    reading_winners.cpp \
    mwindow.cpp

HEADERS += \
    mainwindow.h \
    filedownloader.h \
    mwindow.h

RESOURCES += \
    images.qrc
