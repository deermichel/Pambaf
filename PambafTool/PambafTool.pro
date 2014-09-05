#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T22:56:53
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

#CONFIG += static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PambafTool
TEMPLATE = app

SOURCES += main.cpp\
        PambafTool.cpp

HEADERS  += PambafTool.h

FORMS    += PambafTool.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-PambafLib-Desktop-Release/release/ -lPambafLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-PambafLib-Desktop-Debug/debug/ -lPambafLib
else:unix: LIBS += -L$$PWD/../../build-PambafLib-Desktop-Release/ -lPambafLib

INCLUDEPATH += $$PWD/../PambafLib
DEPENDPATH += $$PWD/../PambafLib
