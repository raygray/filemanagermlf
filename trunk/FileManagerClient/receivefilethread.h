#ifndef RECEIVEFILETHREAD_H
#define RECEIVEFILETHREAD_H

#include <QThread>
#include <QString>

class ReceiveFileThread : public QThread
{
public:
    ReceiveFileThread(const QString &fileName, int id);
protected:
    void run();
private:
    QString m_fileName;
    int m_transId;
};

#endif // RECEIVEFILETHREAD_H
