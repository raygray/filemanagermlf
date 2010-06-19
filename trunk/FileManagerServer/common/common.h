#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QObject>
#include <QString>

class ErrorProcess;

extern ErrorProcess *g_errorProcess; //全局变量，控制错误的处理

bool isSystemDir(QString path); //系统重要的目录，不允许删除
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
