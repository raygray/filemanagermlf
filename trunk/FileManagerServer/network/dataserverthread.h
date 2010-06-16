#ifndef DATASERVERTHREAD_H
#define DATASERVERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QHash>

extern "C"
{
#include <winsock2.h>
}

#include "datatrans.h"

class DataServerThread : public QThread
{
    Q_OBJECT
private:
    explicit DataServerThread(QObject *parent = 0); //单件模式

public:
    static DataServerThread* createServer();
    void addTrans(DataTrans* trans);
    DataTrans* getAndPopTrans(int transId);
signals:
    void errorHappened(int errorCode);

protected:
    void run();

private:
    SOCKET m_socket;
    QMutex m_transListMutex;
    QHash<int, DataTrans* > m_transList;

};

#endif // DATASERVERTHREAD_H
