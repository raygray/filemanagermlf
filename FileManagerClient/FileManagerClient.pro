# -------------------------------------------------
# Project created by QtCreator 2010-06-14T20:02:34
# -------------------------------------------------
QT += xml \
QT -= gui
TARGET = FileManagerClient
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    networkcommon.cpp
HEADERS += networkcommon.h

LIBS += -lws2_32 \
