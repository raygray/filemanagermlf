#include "connectserver.h"
#include "networkcommon.h"
#include "commandchannel.h"

#include <QDebug>


ConnectServer* ConnectServer::createConnectServer(
        const char *ipAddr, int clientId)
{
    static ConnectServer* connectServer =
            new ConnectServer(ipAddr, clientId);
    return connectServer;
}

ConnectServer::ConnectServer(const char *ipAddr, int clientId)
    :m_ipAddr(ipAddr), m_clientId(clientId)
{

}

void ConnectServer::run()
{
    bool first = true;
    while(true)
    {
        if(!first)
        {
            sleep(2);
        }
        first = false;

        SOCKET socketFd;
        socketFd = connectToServer(m_ipAddr, CommandChannelPort);
        if(socketFd == INVALID_SOCKET)
        {
            qDebug() << "connect to server error\n";
            continue;
        }

        CommandChannel::createCommandChannel(socketFd);

    }

}
