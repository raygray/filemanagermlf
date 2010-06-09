#ifndef CLIENTEXPLORER_H
#define CLIENTEXPLORER_H

#include "baseexplorer.h"

class ClientExplorer : public BaseExplorer
{
public:
    ClientExplorer(BaseExplorer *baseExplorer = 0);
    ~ClientExplorer();

};

#endif // CLIENTEXPLORER_H
