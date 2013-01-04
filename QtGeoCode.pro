#-------------------------------------------------
#
# Project created by QtCreator 2013-01-04T15:53:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += network

TARGET = QtGeoCode
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    googlemap.cpp \
    geocodecoreapplication.cpp

unix|win32: LIBS += -lz

unix|win32: LIBS += -lmysqlclient

HEADERS += \
    googlemap.h \
    geocodecoreapplication.h
