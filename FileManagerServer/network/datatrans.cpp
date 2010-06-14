#include "datatrans.h"

DataTrans::DataTrans()
    :m_Id(createId()),
    m_sendedSize(0),
    m_isFailed(false),
    m_isCancelled(false)
{
}

DataTrans::~DataTrans()
{

}

int DataTrans::createId()
{
    static int id = 1;
    return id++;
}


int DataTrans::getId() const
{
    return m_Id;
}

void DataTrans::setCancelled()
{
    m_isCancelled = true;
}

bool DataTrans::isCancelled() const
{
    return m_isCancelled;
}

void DataTrans::setFailed()
{
    m_isFailed = true;
}

bool DataTrans::isFailed() const
{
    return m_isFailed;
}
void DataTrans::setSendedSize(long long sendedSize)
{
    m_sendedSize = sendedSize;
}

long long DataTrans::getSendedSize() const
{
    return m_sendedSize;
}

void DataTrans::setResponseCode(int code)
{
    m_responseCode = code;
}

int DataTrans::getResponseCode() const
{
    return m_responseCode;
}

void DataTrans::setSomethingHappened(int code)
{
    emit SomethingHappened(code);
}

void DataTrans::waitFor()
{
    m_semaphore.acquire();
}

void DataTrans::releaseSemaphore()
{
    m_semaphore.release();
}
