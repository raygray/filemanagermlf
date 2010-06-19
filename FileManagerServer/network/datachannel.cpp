#include "datachannel.h"
#include "networkcommon.h"
#include "dataserverthread.h"
#include "common.h"
#include <QDebug>

DataChannel::DataChannel(SOCKET socket, QObject *parent)
    :QThread(parent),
    m_socket(socket)
{
    setupErrorProcess();
}

void DataChannel::run()
{
    int transId;
    if( ! receiveData(m_socket, (char*)&transId, sizeof(transId)))
    {
        emit errorHappened(ReceiveDataError, __FILE__, __LINE__);
        return ;
    }
    transId = ntohl(transId);

    DataServerThread *server = DataServerThread::createServer();

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


void DataChannel::setupErrorProcess()
{
    extern ErrorProcess * g_errorProcess;
    connect(this, SIGNAL(errorHappened(int,QString,long long)),
            g_errorProcess, SLOT(errorProcess(int,QString,long long)));
}


