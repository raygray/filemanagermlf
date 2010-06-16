#include "connectserver.h"


ConnectServer* ConnectServer::createConnectServer()
{
    static ConnectServer* connectServer = new ConnectServer();
    return connectServer;
}

ConnectServer::ConnectServer()
{
}

void ConnectServer::run()
{

}
