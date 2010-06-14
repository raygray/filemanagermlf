#include "filetrans.h"

#include <cassert>
#include <winsock2.h>

FileTrans::FileTrans()
{
}

FileTrans::FileTrans(const QString &filePath)
    :m_file(filePath)
{
    assert(m_file.exists());
    if(!m_file.open(QFile::ReadOnly))
    {
        //open error
    }
}

FileTrans::FileTrans(const QFileInfo &fileInfo)
    :m_file(fileInfo.absoluteFilePath())
{
    assert(m_file.exists());
    if(!m_file.open(QFile::ReadOnly))
    {
        //open error
    }
}

FileTrans::~FileTrans()
{

}

QByteArray FileTrans::getProtocalPrefix() const
{
    QByteArray result;
    QString filePath = m_file.fileName();
    QString fileName = filePath.mid(filePath.lastIndexOf('/') + 1);
    int fileNameLength = fileName.length();
    result.append((char *)htonl(fileNameLength)); //文件名长度
    result.append(fileName);

    return result;
}
long long FileTrans::readData(char *buffer, long long readSize)
{
    return m_file.read(buffer, readSize);
}

long long FileTrans::dataSize() const
{
    return m_file.size();
}

void FileTrans::setPointer(long long pointer)
{
    m_file.seek(pointer);
    setSendedSize(pointer);
}

QString FileTrans::getFilePath() const
{
    return m_file.fileName();
}
