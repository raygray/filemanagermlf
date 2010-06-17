#ifndef COMMANDCHANNEL_H
#define COMMANDCHANNEL_H

#include <QThread>
#include <QByteArray>

#include "senddatathread.h"
extern "C"
{
#include <winsock2.h>
}

class CommandChannel : public QThread
{
public:
    static CommandChannel* createCommandChannel(SOCKET socket);
    void sendData(const QByteArray& data);

private:
    CommandChannel(SOCKET socket);

public:
    ~CommandChannel();

protected:
    void run();

private:
    SOCKET m_socket;
    SendDataThread *m_sendDataThread;

};

#endif // COMMANDCHANNEL_H
