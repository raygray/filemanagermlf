#ifndef COMMANDCHANNEL_H
#define COMMANDCHANNEL_H

#include <QThread>

class CommandChannel : public QThread
{
public:
    CommandChannel();
};

#endif // COMMANDCHANNEL_H
