#include <QtCore/QCoreApplication>

#include "connectserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ConnectServer::createConnectServer("127.0.0.1", 1)->start();



    return a.exec();
}
