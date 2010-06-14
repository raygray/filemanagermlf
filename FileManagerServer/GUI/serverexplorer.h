#ifndef SERVEREXPLORER_H
#define SERVEREXPLORER_H

#include "baseexplorer.h"

#include <QTreeWidgetItem>
#include <QFileSystemModel>
#include <QScrollBar>
#include <QMenu>
#include <QAction>
#include <QFileInfoList>

class ServerExplorer : public BaseExplorer
{
    Q_OBJECT
public:
    ServerExplorer(BaseExplorer *baseExplorer = 0);
    ~ServerExplorer();

private:
    void setServerSpecificText();
    void createWidgets();
    void setupTreeView();
    void setupFileListView();

    void allConnect();

private slots:
    void pressOnTreeView(const QModelIndex &);
    void clkOnFileList(const QModelIndex &index);
    void doubleClkOnFileList(const QModelIndex & index);

    void popMenuRequested(const QPoint &point);

    void addToTransList();
    void openFileOrDir();
    void renameFile();
    void delFile();

    void clkOnTransButton();

private:
    QFileSystemModel *m_fileSysModel;
    QScrollBar *m_scrollList;



};

#endif // SERVEREXPLORER_H
