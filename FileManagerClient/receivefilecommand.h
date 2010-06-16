#ifndef RECEIVEFILECOMMAND_H
#define RECEIVEFILECOMMAND_H

#include "clientcommand.h"


class ReceiveFileCommand : public ClientCommand
{
public:
    ReceiveFileCommand();

public:
    void doCommand(); //virtual fun
};

#endif // RECEIVEFILECOMMAND_H
