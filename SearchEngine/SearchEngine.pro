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

TEMPLATE = app


SOURCES += main.cpp \
    userinterface.cpp \
    documentparser.cpp

HEADERS += \
    avltree.h \
    userinterface.h \
    documentparser.h \
    ../rapidxml-1.13/rapidxml_iterators.hpp \
    ../rapidxml-1.13/rapidxml_print.hpp \
    ../rapidxml-1.13/rapidxml_utils.hpp \
    ../rapidxml-1.13/rapidxml.hpp
