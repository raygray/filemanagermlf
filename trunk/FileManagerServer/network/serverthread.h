#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QHash>

extern "C"
{
#include <winsock2.h>
}

#include "datatrans.h"

class ServerThread : public QThread
{
    Q_OBJECT
private:
    explicit ServerThread(QObject *parent = 0); //单件模式

public:
    static ServerThread* createServer();
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

#endif // SERVERTHREAD_H
