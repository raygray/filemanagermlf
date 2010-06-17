#ifndef SENDDATATHREAD_H
#define SENDDATATHREAD_H

#include <QThread>
#include <QByteArray>
#include <QMutex>
#include <QWaitCondition>
#include <QLinkedList>

extern "C"
{
#include "winsock2.h"
}


class SendDataThread : public QThread
{
public:
    SendDataThread(SOCKET socket);
    void sendData(const QByteArray& data);

protected:
    void run();

private:
    SOCKET m_socket;
    QMutex m_dataMutex;
    QWaitCondition m_dataCondition;
    QLinkedList<QByteArray> m_dataList;

};

#endif // SENDDATATHREAD_H
