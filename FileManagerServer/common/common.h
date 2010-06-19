#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QObject>
#include <QString>

class ErrorProcess;

extern ErrorProcess *g_errorProcess; //ȫ�ֱ��������ƴ���Ĵ���

bool isSystemDir(QString path); //ϵͳ��Ҫ��Ŀ¼��������ɾ��
void printErrorInfo(QString file, long long line);

///////////////////////////////////
class ErrorProcess : public QObject
{
    Q_OBJECT
private:
    ErrorProcess(QObject *parent = 0);

public:
    static ErrorProcess* createErrorProcess();

public slots:
    void errorProcess(int errorCode, QString file, long long line);

};

////////////////////////////////

#endif // COMMON_H
