#include "receivefilethread.h"
#include "networkcommon.h"
#include <QFile>
#include <QDebug>
#include "boost/scoped_array.hpp"


ReceiveFileThread::ReceiveFileThread(const QString &fileName, int id)
    :m_fileName(fileName), m_transId(id)
{
}

void ReceiveFileThread::run()
{
    SOCKET sockFd = connectToServer(ServerIp.c_str(), DataChannelPort);

    if(INVALID_SOCKET == sockFd)
    {
        qDebug() << "connect to data server error" << __FILE__ << __LINE__;
        return ;
    }
    if(!sendData(sockFd, FBtoNetworkCharP(m_transId), sizeof(m_transId)))
    {
        qDebug() << "send transfer Id error"<< __FILE__ << __LINE__;
        return ;
    }

    QFile saveFile(m_fileName);
    unsigned long fileStatusCode;
    if(saveFile.exists())
    {
        fileStatusCode = 0x0;
    }
    else
    {
        fileStatusCode = 0x1;
    }

    if(!sendData(sockFd, FBtoNetworkCharP(fileStatusCode), sizeof(fileStatusCode)))
    {
        qDebug() << "send file status code error"<< __FILE__ << __LINE__;
        return ;
    }

    unsigned long fileResponseCode;
    if(!getFourByte(sockFd, fileResponseCode))
    {
        qDebug() << "get file response code error" <<__FILE__ << __LINE__;
        return ;
    }

    if(fileResponseCode == 0x0 || fileResponseCode == 0x1) //覆盖或者文件不存在
    {
        if(!saveFile.open(QFile::WriteOnly))
        {
            qDebug() << "open file to write error" << __FILE__ << __LINE__;
            closesocket(sockFd);
            return ;
        }
    }
    else if(fileResponseCode == 0x2) //已存在，跳过传输
    {
        qDebug() << "server agree not to transfer the existed file";
        closesocket(sockFd);
        return ;
    }
    else if (fileResponseCode == 0x3)
    {
        long long fileCurrentLength = saveFile.size();
        unsigned long lowPart = fileCurrentLength;
        unsigned long highPart = fileCurrentLength >> 32;

        if(!sendData(sockFd, FBtoNetworkCharP(lowPart), sizeof(lowPart)))
        {
            qDebug() << "send file exist file length low part error" << __FILE__ << __LINE__;
            return ;
        }
        if(!sendData(sockFd, FBtoNetworkCharP(highPart), sizeof(highPart)))
        {
            qDebug() << "send file exist file length high part error" << __FILE__ << __LINE__;
            return ;
        }

        if(!saveFile.open(QFile::Append))
        {
            qDebug()<<"open the file to write error"<< __FILE__ << __LINE__;
            return ;
        }
    }

    const unsigned long bufferSize = 50000;
    char *buffer = new char[bufferSize];
    boost::scoped_array<char> bufferContainer(buffer);
    while(true)
    {
        int readSize;
        readSize = recv(sockFd, buffer, bufferSize, 0);

        if(readSize == SOCKET_ERROR)
        {
            qDebug() <<"receive data from server error" << __FILE__ << __LINE__;
            saveFile.close();
        }
        else if (readSize == 0)
        {
            saveFile.close();
            break;
        }
        saveFile.write(buffer, readSize);
    }
}
