#include "datatransfer.h"

DataTransfer::DataTransfer()
{
}
int DataTransfer::getId() const
{
    return m_Id;
}

void DataTransfer::setCancelled()
{
    m_isCancelled = true;
}

bool DataTransfer::isCancelled() const
{
    return m_isCancelled;
}

void DataTransfer::setFailed()
{
    m_isFailed = true;
}

bool DataTransfer::isFailed() const
{
    return m_isFailed;
}
void DataTransfer::setSendedSize(long long sendedSize)
{
    m_sendedSize = sendedSize;
}

long long DataTransfer::getSendedSize() const
{
    return m_sendedSize;
}

void DataTransfer::setResponseCode(int code)
{
    m_responseCode = code;
}

int DataTransfer::getResponseCode() const
{
    return m_responseCode;
}

void DataTransfer::setSomethingHappened(int code);

void DataTransfer::waitFor();
void DataTransfer::releaseSemaphore();
