# -------------------------------------------------
# Project created by QtCreator 2010-06-08T12:41:54
# -------------------------------------------------
QT += network \
    xml
TARGET = FileManagerServer
INCLUDEPATH += . \
    GUI \
    network \
    other \
    common \
    transmission \
    TEMPLATE \
    = \
    app
SOURCES += main.cpp \
    mainwindow.cpp \
    GUI\baseexplorer.cpp \
    GUI\serverexplorer.cpp \
    GUI\clientexplorer.cpp \
    common\parameter.cpp \
    common/common.cpp \
    network/datatrans.cpp \
    network/filetrans.cpp \
    network/serverthread.cpp \
    network/networkcommon.cpp \
    network/datachannel.cpp \
    network/commandchannel.cpp \
    network/commandserverthread.cpp
HEADERS += mainwindow.h \
    GUI\baseexplorer.h \
    GUI\serverexplorer.h \
    GUI\clientexplorer.h \
    common\parameter.h \
    common/common.h \
    network/datatrans.h \
    network/filetrans.h \
    network/serverthread.h \
    network/networkcommon.h \
    network/datachannel.h \
    network/commandchannel.h \
    network/commandserverthread.h
LIBS += -lws2_32
