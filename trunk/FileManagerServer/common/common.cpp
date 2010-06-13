#include "common.h"
#include <QStringList>
#include <QDir>

static QStringList g_sysDir;

static bool g_firstRun = true;

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
