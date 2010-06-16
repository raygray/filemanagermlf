#ifndef COMMANDCHANNEL_H
#define COMMANDCHANNEL_H

#include <QThread>

#include "senddatathread.h"
extern "C"
{
#include <winsock2.h>
}

class CommandChannel : public QThread
{
public:
    CommandChannel();

protected:
    void run();

private:
    SOCKET m_socket;
    SendDataThread *m_sendDataThread;

};

#endif // COMMANDCHANNEL_H
