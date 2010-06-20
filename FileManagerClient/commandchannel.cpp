#include "commandchannel.h"
#include "boost/scoped_array.hpp"
#include "networkcommon.h"

CommandChannel* CommandChannel::createCommandChannel(SOCKET socket)
{
    static CommandChannel* commandChannel =
            new CommandChannel(socket);
    commandChannel->start();
    return commandChannel;
}

CommandChannel::CommandChannel(SOCKET socket)
    :m_socket(socket)
{
    m_sendDataThread = new SendDataThread(m_socket);
    m_sendDataThread->start();
}

CommandChannel::~CommandChannel()
{
    if(m_sendDataThread)
        delete m_sendDataThread;
}

void CommandChannel::sendData(const QByteArray &data)
{
    m_sendDataThread->sendData(data);
}


void CommandChannel::run()
{
    const unsigned long bufferSize = 50000;
    char *buffer = new char[bufferSize];
    boost::scoped_array<char> bufferContainer(buffer);

    unsigned long tempCode = 0x20;
    unsigned long length = 4;
    unsigned long degree = 80;

    QByteArray dataArray;
    dataArray.append(FBtoNetworkCharP(tempCode), 4);
    dataArray.append(FBtoNetworkCharP(length), 4);
    dataArray.append(FBtoNetworkCharP(degree), 4);

    m_sendDataThread->sendData(dataArray);

//    while(true)
//    {
//
//    }


}
