#include "networkcommon.h"
extern "C"
{
#include <winsock2.h>
}

const unsigned short CommandChannelPort = 2067;
const unsigned short DataChannelPort = 2922;

//初始化检查Socket版本
bool setupSocketLib()
{
    WSAData wsaData;
    WORD version = MAKEWORD(2,2);

    int ret = WSAStartup(version, &wsaData);
    return ret == 0;
}

//连接服务器
SOCKET connectToServer(const char *ipAddr, unsigned short port)
{
    SOCKET socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == INVALID_SOCKET)
    {
        return socketFd;
    }

    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ipAddr);
    serverAddr.sin_port = htons(port);

    if( SOCKET_ERROR == connect(socketFd,
                                (SOCKADDR *)&serverAddr,
                                sizeof(serverAddr))  )
    {
        closesocket(socketFd);
        return INVALID_SOCKET;
    }

    return socketFd;
}

//发送数据
bool sendData(SOCKET socket, const char *data, long long size)
{
    long long sendedSize = 0;
    while(sendedSize < size)
    {
        long long tmp = send(socket, data + sendedSize, size - sendedSize, 0);
        if ( tmp == SOCKET_ERROR )
        {
            return false;
        }
        sendedSize += tmp;
    }
    return true;
}

//接收数据
bool receiveData(SOCKET socket, char *buffer, long long size)
{
    long long receivedSize = 0;
    while(receivedSize < size)
    {
        long long tmp = recv(socket, buffer + receivedSize, size - receivedSize, 0);
        if ( tmp == SOCKET_ERROR )
        {
            return false;
        }
        else if ( tmp == 0)
        {
            return false;
        }
        receivedSize += tmp;
    }
    return true;
}

