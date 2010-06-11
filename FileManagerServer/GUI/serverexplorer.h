#ifndef SERVEREXPLORER_H
#define SERVEREXPLORER_H

#include "baseexplorer.h"

#include <QTreeWidgetItem>
#include <QFileSystemModel>

class ServerExplorer : public BaseExplorer
{
public:
    ServerExplorer(BaseExplorer *baseExplorer = 0);
    ~ServerExplorer();

public:
    void setupTreeView();

private:
    void setServerSpecificText();
    void createModel();

private:
    QFileSystemModel *m_fileSysModel;

};

#endif // SERVEREXPLORER_H
