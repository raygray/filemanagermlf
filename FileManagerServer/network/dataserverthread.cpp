#include "dataserverthread.h"
#include "networkcommon.h"

DataServerThread::DataServerThread(QObject *parent)
    :QThread(parent)
{
}

DataServerThread* DataServerThread::createServer()
{
    static DataServerThread* server = new DataServerThread();
    server->start();
    return server;
}

void DataServerThread::run()
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket == INVALID_SOCKET)
    {
        emit errorHappened(CreateSocketError);
        return ;
    }
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(DataChannelPort);

    if(SOCKET_ERROR ==
       bind(m_socket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)))
    {
        emit errorHappened(BindError);
        return ;
    }

    if(SOCKET_ERROR ==
       listen(m_socket, SOMAXCONN))
    {
        emit errorHappened(ListenError);
        return ;
    }

    while(true)
    {
        SOCKET clientSocket;
        SOCKADDR_IN clientAddr;
        int clientAddrSize = sizeof(clientAddr);
        clientSocket = accept(m_socket,
                              (SOCKADDR*)&clientAddr,
                              &clientAddrSize);
        if(clientSocket == INVALID_SOCKET)
        {
            emit errorHappened(AcceptError);
            continue;
        }

    }

}


void DataServerThread::addTrans(DataTrans *trans)
{

}

DataTrans* DataServerThread::getAndPopTrans(int transId)
{
    return 0;
}
