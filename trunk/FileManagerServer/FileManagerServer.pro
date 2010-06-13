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
    common/common.cpp
HEADERS += mainwindow.h \
    GUI\baseexplorer.h \
    GUI\serverexplorer.h \
    GUI\clientexplorer.h \
    common\parameter.h \
    common/common.h
