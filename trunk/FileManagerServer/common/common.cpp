#include "common.h"
#include <QStringList>
#include <QDir>
#include <QDebug>
#include "networkcommon.h"

static QStringList g_sysDir;

static bool g_firstRun = true;

ErrorProcess *g_errorProcess; //全局变量，控制错误的处理

bool isSystemDir(const QString path)
{
    if(g_firstRun)
    {
        //QString sep(QDir::separator());
        QString sep("/");
        g_sysDir.append(QString("C:") + sep + "windows");
        g_sysDir.append(QString("C:") + sep + "windows" + sep + "system");
        g_sysDir.append(QString("C:") + sep + "windows" + sep + "system32");
        g_sysDir.append(QString("C:") + sep + "Program Files");
        g_sysDir.append(QString("C:") + sep + "Documents and Settings");

        g_firstRun = false;
    }

    if(g_sysDir.contains(path, Qt::CaseInsensitive))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printErrorInfo(QString filename, long long line)
{
    qDebug() << "Error happened in : " << filename << line;
}


//////////////////////////////////////////////
// functions of class ErrorProcess

ErrorProcess::ErrorProcess(QObject *parent)
    :QObject(parent)
{
}

ErrorProcess* ErrorProcess::createErrorProcess()
{
    static ErrorProcess *errorProc = new ErrorProcess();
    return errorProc;
}

void ErrorProcess::errorProcess(int errorCode, QString file, long long line)
{
    printErrorInfo(file, line); //打印出出错的文件和行号

    switch(errorCode)
    {
    case FileOpenError:
        qDebug() << tr("!!!ERROR!!! file open error\n");
        break;
    case FileReadError:
        qDebug() << tr("!!!ERROR!!! file read error\n");
        break;
    case FileWriteError:
        qDebug() << tr("!!!ERROR!!! file write error\n");
        break;
    case CreateSocketError:
        qDebug() << tr("!!!ERROR!!! create socket error\n");
        break;
    case BindError:
        qDebug() << tr("!!!ERROR!!! bind socket error\n");
        break;
    case ListenError:
        qDebug() << tr("!!!ERROR!!! listen socket error\n");
        break;
    case AcceptError:
        qDebug() << tr("!!!ERROR!!! accept socket error\n");
        break;
    case SendDataError:
        qDebug() << tr("!!!ERROR!!! send data error\n");
        break;
    case ReceiveDataError:
        qDebug() << tr("!!!ERROR!!! receive data error\n");
        break;
    default:
        qDebug() << tr("!!!ERROR!!! unknown error\n");
        break;
    }
}

/////////////////////////////////////////////////////////////
