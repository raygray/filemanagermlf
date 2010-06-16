#include "datachannel.h"
#include "networkcommon.h"
#include "serverthread.h"
#include <QDebug>

DataChannel::DataChannel(SOCKET socket, QObject *parent)
    :QThread(parent),
    m_socket(socket)
{
}

void DataChannel::run()
{
    int transId;
    if( ! receiveData(m_socket, (char*)&transId, sizeof(transId)))
    {
        emit errorHappened(ReceiveDataError);
        return ;
    }
    transId = ntohl(transId);

    ServerThread *server = ServerThread::createServer();

    DataTrans *dataTrans;
    try
    {
        dataTrans = server->getAndPopTrans(transId);
    }
    catch(...)
    {
        qDebug() << tr("无法找到对应的传输数据");
        return ;
    }
    ///
    //

}



