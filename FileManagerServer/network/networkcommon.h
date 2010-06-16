#ifndef NETWORKCOMMON_H
#define NETWORKCOMMON_H

// 使用winsock2 需要在编译选项中加入-lws_32
// 在.pro中加入 LIBS += -lws2_32 \ 即可


extern "C"
{
#include <winsock2.h>
}

bool setupSocketLib(); //初始化检查Socket版本

SOCKET connectToServer(const char *ipAddr, unsigned short port); //连接服务器

bool sendData(SOCKET socket, const char *data, long long size); //发送数据

bool receiveData(SOCKET socket, char *buffer, long long size); //接收数据

enum ErrorCode{
        FileOpenError, FileReadError, FileWriteError,
        CreateSocketError, BindError, ListenError, AcceptError,
        SendDataError, ReceiveDataError
};


#endif // NETWORKCOMMON_H
