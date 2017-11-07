#-------------------------------------------------
#
# Project created by QtCreator 2017-09-10T16:49:35
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Adventure_Game
TEMPLATE = app

SOURCES += main.cpp\
    object.cpp \
    july5.cpp \
    consoleutilities.cpp \
    location.cpp \
    door.cpp \
    key.cpp \
    inventoryobject.cpp \
    inventory.cpp \
    locationmanager.cpp \
    eventmanager.cpp \
    locationui.cpp \
    updateable.cpp \
    mainwindow.cpp \
    verbmanager.cpp \
    objectbutton.cpp \
    maploader.cpp \
    imageutilities.cpp \
    audiomanager.cpp \
    food.cpp

HEADERS  += \
    object.h \
    july5.h \
    consoleutilities.h \
    location.h \
    door.h \
    key.h \
    inventoryobject.h \
    inventory.h \
    locationmanager.h \
    eventmanager.h \
    updateable.h \
    locationui.h \
    mainwindow.h \
    verb.h \
    verbmanager.h \
    objectbutton.h \
    event.h \
    maploader.h \
    imageutilities.h \
    audiomanager.h \
    food.h

FORMS    += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES += \
    gfx.qrc

DISTFILES += \
    map/map.txt
