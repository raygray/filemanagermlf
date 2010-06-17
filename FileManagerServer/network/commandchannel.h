#ifndef COMMANDCHANNEL_H
#define COMMANDCHANNEL_H

#include <QThread>
extern "C"
{
#include "winsock2.h"
}


class CommandChannel : public QThread
{
public:
    CommandChannel();

public:
    void run(); //virtual fun from QThread

private:
    SOCKET m_socket;

};

#endif // COMMANDCHANNEL_H
