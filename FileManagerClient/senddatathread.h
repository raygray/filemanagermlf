#ifndef SENDDATATHREAD_H
#define SENDDATATHREAD_H

#include <QThread>

class SendDataThread : public QThread
{
public:
    SendDataThread();

protected:
    void run();

};

#endif // SENDDATATHREAD_H
