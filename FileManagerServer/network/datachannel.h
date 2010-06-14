#ifndef DATACHANNEL_H
#define DATACHANNEL_H

#include <QThread>
#include <QString>

extern "C"
{
#include <winsock2.h>
}

class DataChannel : public QThread
{
    Q_OBJECT
public:
    explicit DataChannel(SOCKET socket, QObject *parent = NULL);

signals:
    void errorHappened(int errorCode);

public slots:

protected:
    void run();

private:
    SOCKET m_socket;
};

#endif // DATACHANNEL_H
