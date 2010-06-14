#ifndef DATATRANSFER_H
#define DATATRANSFER_H

#include <QObject>
#include <QSemaphore>

class DataTransfer : public QObject
{
    Q_OBJECT
public:
    DataTransfer();
    virtual ~DataTransfer();

public:
    int getId() const;

    void setCancelled();
    bool isCancelled() const;

    void setFailed();
    bool isFailed() const;

    void setSendedSize(long long sendedSize);
    long long getSendedSize() const;

    void setResponseCode(int code);
    int getResponseCode() const;

    void setSomethingHappened(int code);

    void waitFor();
    void releaseSemaphore();

public:
    /*
      getProtocalPrefix:得到要发送数据的协议头,其中应该包含传送数据保存的文件名，文件名长度，数据大小等
              return:要发送数据的协议头
      */
    virtual QByteArray getProtocalPrefix() const = 0;

    /*
      readData:从要发送的数据当中读取一些出来准备发送
              buffer:读取的目的地
              readSize:要读取的大小，注意不能大于buffer的长度
              return:返回真实读取的大小
      */
    virtual long long readData(char* buffer, long long readSize) = 0;

    /*
      dataSize:数据总量的大小
              return:数据总量大小
      */
    virtual long long dataSize() const = 0;

    virtual void setPointer(long long pointer) = 0;

signals:
    void SomethingHappened(int code);

private:
    static int createId();

private:
    int m_Id;
    long long m_sendedSize;
    bool m_isFailed;
    bool m_isCancelled;
    QSemaphore m_semaphore;
    int m_responseCode;

};

#endif // DATATRANSFER_H
