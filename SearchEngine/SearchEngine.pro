#-------------------------------------------------
#
# Project created by QtCreator 2014-11-12T00:14:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SearchEngine
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    userinterface.cpp \
    documentparser.cpp

HEADERS += \
    avltree.h \
    userinterface.h \
    documentparser.h
