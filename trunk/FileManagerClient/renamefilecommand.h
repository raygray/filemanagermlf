#ifndef RENAMEFILECOMMAND_H
#define RENAMEFILECOMMAND_H

#include "clientcommand.h"

class RenameFileCommand : public ClientCommand
{
public:
    RenameFileCommand();

public:
    void doCommand(); //virtual fun
};

#endif // RENAMEFILECOMMAND_H
