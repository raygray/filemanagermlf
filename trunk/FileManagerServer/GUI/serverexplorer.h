#ifndef SERVEREXPLORER_H
#define SERVEREXPLORER_H

#include "baseexplorer.h"

class ServerExplorer : public BaseExplorer
{
public:
    ServerExplorer(BaseExplorer *baseExplorer = 0);
    ~ServerExplorer();

public:
    void InitTreeView();

private:
    void setServerSpecificText();

};

#endif // SERVEREXPLORER_H
