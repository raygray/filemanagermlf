#include "senddatathread.h"
#include "networkcommon.h"
#include <QDebug>

SendDataThread::SendDataThread(SOCKET socket)
    :m_socket(socket)
{
}

void SendDataThread::sendData(const QByteArray &data)
{
    //防止不停的命令发送过来，先存储，然后慢慢发送
    QMutexLocker locker(&m_dataMutex);
    m_dataList.push_back(data);
    m_dataCondition.wakeAll();
}

void SendDataThread::run()
{
    while(true)
    {
        QMutexLocker locker(&m_dataMutex);
        m_dataCondition.wait(&m_dataMutex);

        int count = m_dataList.count();

        for( int i = 0; i < count; ++i)
        {
            const QByteArray& data = m_dataList.first();
            if(! ::sendData(m_socket, data.data(), data.size()))
            {
                qDebug() << "send data to server error\n";
                return ;
            }
            m_dataList.pop_front();
        }
    }
}
