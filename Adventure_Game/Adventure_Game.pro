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
    object.cpp \
    cliframe.cpp \
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
    updateable.cpp

HEADERS  += \
    object.h \
    cliframe.h \
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
    locationui.h

FORMS    += \
    cliframe.ui

QMAKE_CXXFLAGS += -std=c++11
QMAKE_MAC_SDK = macosx10.13

RESOURCES += \
    gfx.qrc
