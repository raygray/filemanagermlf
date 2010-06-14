#include "serverthread.h"
#include "networkcommon.h"

ServerThread::ServerThread(QObject *parent)
    :QThread(parent)
{
}

ServerThread* ServerThread::createServer()
{
    static ServerThread* server = new ServerThread();
    server->start();
    return server;
}

void ServerThread::run()
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
    serverAddr.sin_port = htons(2105);

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


void ServerThread::addTrans(DataTrans *trans)
{

}

DataTrans* ServerThread::getAndPopTrans(int transId)
{
    return 0;
}
