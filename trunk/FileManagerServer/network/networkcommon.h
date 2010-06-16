#ifndef NETWORKCOMMON_H
#define NETWORKCOMMON_H

// ʹ��winsock2 ��Ҫ�ڱ���ѡ���м���-lws_32
// ��.pro�м��� LIBS += -lws2_32 \ ����


extern "C"
{
#include <winsock2.h>
}

bool setupSocketLib(); //��ʼ�����Socket�汾

SOCKET connectToServer(const char *ipAddr, unsigned short port); //���ӷ�����

bool sendData(SOCKET socket, const char *data, long long size); //��������

bool receiveData(SOCKET socket, char *buffer, long long size); //��������

enum ErrorCode{
        FileOpenError, FileReadError, FileWriteError,
        CreateSocketError, BindError, ListenError, AcceptError,
        SendDataError, ReceiveDataError
};


#endif // NETWORKCOMMON_H
