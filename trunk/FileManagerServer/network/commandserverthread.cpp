#include "commandserverthread.h"
#include "networkcommon.h"


CommandServerThread* CommandServerThread::createServer()
{
    static CommandServerThread *commandServerThread = new CommandServerThread();
    commandServerThread->start();
    return commandServerThread;
}

CommandServerThread::CommandServerThread(QObject *parent)
    :QThread(parent)
{
}

void CommandServerThread::run()
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket == INVALID_SOCKET)
    {
        emit errorHappened(CreateSocketError);
        return ;
    }

    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;
    //serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(CommandChannelPort); //默认命令通道端口号define in networkcommon.h

    if (SOCKET_ERROR ==
        bind(m_socket, (SOCKADDR *)&serverAddr, sizeof(serverAddr)))
    {
        emit errorHappened(BindError);
        return ;
    }

    if (SOCKET_ERROR ==
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
