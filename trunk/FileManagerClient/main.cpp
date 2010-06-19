#include <QtCore/QCoreApplication>

#include "connectserver.h"
#include "networkcommon.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setupSocketLib();
    ConnectServer::createConnectServer("127.0.0.1", 1)->start();



    return a.exec();
}
