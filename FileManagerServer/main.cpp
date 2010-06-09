#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTextCodec>

int main(int argc, char *argv[])
{
    // �������ı���
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
