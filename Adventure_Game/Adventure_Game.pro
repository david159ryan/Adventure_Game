#-------------------------------------------------
#
# Project created by QtCreator 2017-09-10T16:49:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Adventure_Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    object.cpp \
    cliframe.cpp \
    july5.cpp \
    rustyknife.cpp \
    consoleutilities.cpp

HEADERS  += mainwindow.h \
    object.h \
    cliframe.h \
    july5.h \
    rustyknife.h \
    consoleutilities.h

FORMS    += mainwindow.ui \
    cliframe.ui

QMAKE_CXXFLAGS += -std=c++11
