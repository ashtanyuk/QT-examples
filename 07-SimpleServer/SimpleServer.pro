#-------------------------------------------------
#
# Project created by QtCreator 2014-04-10T14:38:24
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = SimpleServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mytcpserver.cpp

HEADERS += \
    mytcpserver.h
