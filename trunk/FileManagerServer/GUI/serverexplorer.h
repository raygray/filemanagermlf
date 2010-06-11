#ifndef SERVEREXPLORER_H
#define SERVEREXPLORER_H

#include "baseexplorer.h"

#include <QTreeWidgetItem>
#include <QFileSystemModel>

class ServerExplorer : public BaseExplorer
{
    Q
public:
    ServerExplorer(BaseExplorer *baseExplorer = 0);
    ~ServerExplorer();

private:
    void setServerSpecificText();
    void createModel();
    void setupTreeView();
    void setupFileListView();
    void allConnect();

private slots:
    void doubleClkOnFileList();

private:
    QFileSystemModel *m_fileSysModel;

};

#endif // SERVEREXPLORER_H
