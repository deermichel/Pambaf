#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T19:24:23
#
#-------------------------------------------------

QT       -= core gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = PambafLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += PambafLib.cpp

HEADERS += PambafLib.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
