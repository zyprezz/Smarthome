#-------------------------------------------------
#
# Project created by QtCreator 2017-04-10T12:59:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Smarthome
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    i2c.cpp \
    calendar.cpp \
    filehandler.cpp \
    lysstyring.cpp \
    varmestyring.cpp \
    gardinstyring.cpp

HEADERS  += mainwindow.h \
    i2c.h \
    calendar.h \
    filehandler.h \
    lysstyring.h \
    varmestyring.h \
    gardinstyring.h

FORMS    += mainwindow.ui \
    lysstyring.ui \
    varmestyring.ui \
    gardinstyring.ui

RESOURCES += \
    files.qrc
