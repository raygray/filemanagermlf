#ifndef NETWORKCOMMON_H
#define NETWORKCOMMON_H

// 使用Winsock2 需要在编译选项中加入-lws_32
// 在.pro中加入 LIBS += -lws2_32 \ 即可


extern "C"
{
#include <winsock2.h>
}
#include <string>

extern std::string ServerIp;
extern const unsigned short CommandChannelPort; //命令通道端口号
extern const unsigned short DataChannelPort;    //数据通道端口号


bool setupSocketLib(); //初始化检查Socket版本

SOCKET connectToServer(const char *ipAddr, unsigned short port); //连接服务器

bool sendData(SOCKET socket, const char *data, long long size); //发送数据

bool receiveData(SOCKET socket, char *buffer, long long size); //接收数据

//从网络当中得到4个字节数据，并转换为主机字节序
template<typename Type>
bool getFourByte(SOCKET socket, Type& value)
{
        if(!receiveData(socket, reinterpret_cast<char*>(&value), sizeof(value)))
        {
                return false;
        }

        value = ntohl(value);
        return true;
}

//从4字节的数据转换为网络字节序并返回其char*的地址
template<typename Type>
char* FBtoNetworkCharP(Type &beforeTransform)
{
        beforeTransform = htonl(beforeTransform);
        return reinterpret_cast<char*>(&beforeTransform);
}


enum ErrorCode{
        FileOpenError, FileReadError, FileWriteError,
        CreateSocketError, BindError, ListenError, AcceptError,
        SendDataError, ReceiveDataError
};



#endif // NETWORKCOMMON_H
