#ifndef COMMANDSERVERTHREAD_H
#define COMMANDSERVERTHREAD_H

#include <QThread>
#include <QString>

#include "networkcommon.h"

extern "C"
{
#include "winsock2.h"
}

class CommandServerThread : public QThread
{
    Q_OBJECT
public:
    static CommandServerThread* createServer();

private:
    explicit CommandServerThread(QObject *parent = 0);

signals:
    void errorHappened(int errorCode, QString file, long long line);

public:
    void run(); //virtual fun from QThread

private:
    void setupErrorProcess();

private:
    SOCKET m_socket;

};

#endif // COMMANDSERVERTHREAD_H
