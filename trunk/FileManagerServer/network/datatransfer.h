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
      getProtocalPrefix:�õ�Ҫ�������ݵ�Э��ͷ,����Ӧ�ð����������ݱ�����ļ������ļ������ȣ����ݴ�С��
              return:Ҫ�������ݵ�Э��ͷ
      */
    virtual QByteArray getProtocalPrefix() const = 0;

    /*
      readData:��Ҫ���͵����ݵ��ж�ȡһЩ����׼������
              buffer:��ȡ��Ŀ�ĵ�
              readSize:Ҫ��ȡ�Ĵ�С��ע�ⲻ�ܴ���buffer�ĳ���
              return:������ʵ��ȡ�Ĵ�С
      */
    virtual long long readData(char* buffer, long long readSize) = 0;

    /*
      dataSize:���������Ĵ�С
              return:����������С
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
