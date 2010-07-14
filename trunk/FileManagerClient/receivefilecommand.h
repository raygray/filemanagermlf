#ifndef RECEIVEFILECOMMAND_H
#define RECEIVEFILECOMMAND_H

#include "clientcommand.h"
#include "receivefilethread.h"

class ReceiveFileCommand : public ClientCommand
{
public:
    explicit ReceiveFileCommand(const char *fileName, int transId);
    ~ReceiveFileThread();

    QString getFileName() const;
    int getTransId() const;

public:
    void doCommand(); //virtual fun

private:

};

#endif // RECEIVEFILECOMMAND_H
