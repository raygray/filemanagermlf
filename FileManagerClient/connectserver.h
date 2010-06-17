//
// 连接服务器
//

#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <QThread>
#include <QSemaphore>

extern "C"
{
#include <winsock2.h>
}

class ConnectServer : public QThread
{
public:
    static ConnectServer* createConnectServer(
            const char *ipAddr, int clientId);

protected:
    void run();

private:
    ConnectServer(const char *ipAddr, int clientId);

private:
    const char *m_ipAddr;
    int m_clientId;
};

#endif // CONNECTSERVER_H
