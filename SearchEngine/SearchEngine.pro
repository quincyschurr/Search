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
    documentparser.cpp \
    word.cpp \
    page.cpp \
    stopword.cpp \
    indexhandler.cpp \
    hashtable.cpp \
    avl2.cpp \
    query.cpp

HEADERS += \
    avltree.h \
    userinterface.h \
    documentparser.h \
    word.h \
    page.h \
    stopword.h \
    rapidxml_utils.hpp \
    rapidxml.hpp \
    indexhandler.h \
    hashtable.h \
    porterstem.h \
    avl2.h \
    AVLNODE.h \
    query.h
