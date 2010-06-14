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
}


void ServerThread::addTrans(DataTrans *trans)
{

}

DataTrans* ServerThread::getAndPopTrans(int transId)
{

}
