#ifndef FILETRANS_H
#define FILETRANS_H

#include "datatrans.h"
#include <QString>
#include <QFileInfo>
#include <QFile>

class FileTrans : public DataTrans
{
public:
    FileTrans();
    FileTrans(const QString &filePath);
    FileTrans(const QFileInfo &fileInfo);
    ~FileTrans(); //virtual

public:
    QByteArray getProtocalPrefix() const; //virtual
    long long readData(char *buffer, long long readSize); //virtual
    long long dataSize() const; //virtual
    void setPointer(long long pointer); //virtual

public:
    QString getFilePath() const;

private:
    QFile m_file;

};

#endif // FILETRANS_H
