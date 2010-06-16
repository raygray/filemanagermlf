# -------------------------------------------------
# Project created by QtCreator 2010-06-14T20:02:34
# -------------------------------------------------
QT += xml \
    QT \
    -= \
    gui
TARGET = FileManagerClient
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    networkcommon.cpp \
    commandchannel.cpp \
    clientcommand.cpp \
    connectserver.cpp \
    senddatathread.cpp \
    receivefilecommand.cpp \
    delfilecommand.cpp \
    renamefilecommand.cpp
HEADERS += networkcommon.h \
    commandchannel.h \
    clientcommand.h \
    connectserver.h \
    senddatathread.h \
    receivefilecommand.h \
    delfilecommand.h \
    renamefilecommand.h
LIBS += -lws2_32
