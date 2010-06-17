#ifndef COMMANDSERVERTHREAD_H
#define COMMANDSERVERTHREAD_H

#include <QThread>

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
    void errorHappened(int errorCode);

public:
    void run(); //virtual fun from QThread

private:
    SOCKET m_socket;

};

#endif // COMMANDSERVERTHREAD_H
