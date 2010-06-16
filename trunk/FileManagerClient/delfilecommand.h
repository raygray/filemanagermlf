#ifndef DELFILECOMMAND_H
#define DELFILECOMMAND_H

#include "clientcommand.h"

class DelFileCommand : public ClientCommand
{
public:
    DelFileCommand();

public:
    void doCommand(); //virtual fun
};

#endif // DELFILECOMMAND_H
