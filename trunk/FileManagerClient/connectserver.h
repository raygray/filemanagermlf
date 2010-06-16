//
// 连接服务器
//

#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <QThread>
#include <QSemaphore>

class ConnectServer : public QThread
{
public:
    static ConnectServer* createConnectServer();

protected:
    void run();

private:
    ConnectServer();
};

#endif // CONNECTSERVER_H
