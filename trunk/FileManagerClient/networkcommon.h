#ifndef NETWORKCOMMON_H
#define NETWORKCOMMON_H

// ʹ��Winsock2 ��Ҫ�ڱ���ѡ���м���-lws_32
// ��.pro�м��� LIBS += -lws2_32 \ ����


extern "C"
{
#include <winsock2.h>
}
#include <string>

extern std::string ServerIp;
extern const unsigned short CommandChannelPort; //����ͨ���˿ں�
extern const unsigned short DataChannelPort;    //����ͨ���˿ں�


bool setupSocketLib(); //��ʼ�����Socket�汾

SOCKET connectToServer(const char *ipAddr, unsigned short port); //���ӷ�����

bool sendData(SOCKET socket, const char *data, long long size); //��������

bool receiveData(SOCKET socket, char *buffer, long long size); //��������

//�����統�еõ�4���ֽ����ݣ���ת��Ϊ�����ֽ���
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

//��4�ֽڵ�����ת��Ϊ�����ֽ��򲢷�����char*�ĵ�ַ
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
