#include "commandserverthread.h"
#include "common.h"

#include <QDebug>

CommandServerThread* CommandServerThread::createServer()
{
    static CommandServerThread *commandServerThread = new CommandServerThread();
    commandServerThread->start();
    qDebug() << tr("Command server thread started\n");
    return commandServerThread;
}

CommandServerThread::CommandServerThread(QObject *parent)
    :QThread(parent)
{
    setupErrorProcess();
}

void CommandServerThread::run()
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket == INVALID_SOCKET)
    {
        emit errorHappened(CreateSocketError, __FILE__, __LINE__);
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
        emit errorHappened(BindError, __FILE__, __LINE__);
        return ;
    }

    if (SOCKET_ERROR ==
        listen(m_socket, SOMAXCONN))
    {
        emit errorHappened(ListenError, __FILE__, __LINE__);
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
            emit errorHappened(AcceptError, __FILE__, __LINE__);
            continue;
        }
    }
}

void CommandServerThread::setupErrorProcess()
{
    extern ErrorProcess * g_errorProcess;
    connect(this, SIGNAL(errorHappened(int,QString,long long)),
            g_errorProcess, SLOT(errorProcess(int,QString,long long)));
}
