#include "serverexplorer.h"
#include <QLocale>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

#include "common.h"



ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setServerSpecificText(); //设置一些控件的显示文字
    createWidgets();
    setupTreeView();
    setupFileListView();

    allConnect();

}

ServerExplorer::~ServerExplorer()
{

}

void ServerExplorer::setServerSpecificText()
{
    QMap<QString, QString> paraMap;
    paraMap.insert("typeLabel", tr("<font color = green>服务器</font>"));
    paraMap.insert("transButton", tr("发送到客户端"));
    paraMap.insert("currentPathLabel", tr("<font color = green>路径</font>"));
    Parameter parameter(paraMap);

    setSpecificText(parameter);
}

void ServerExplorer::createWidgets()
{
    m_fileSysModel = new QFileSystemModel(this);
    m_fileSysModel->setRootPath("");
    //m_fileSysModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    m_scrollList = new QScrollBar(this);

}

void ServerExplorer::setupTreeView()
{
    m_treeView->setModel(m_fileSysModel);
    m_treeView->setHeaderHidden(true);
    m_treeView->sortByColumn(0, Qt::AscendingOrder);
    //m_treeView->setSortingEnabled(true);
    m_treeView->setColumnHidden(1, true);
    m_treeView->setColumnHidden(2, true);
    m_treeView->setColumnHidden(3, true);
    m_treeView->setAnimated(false);
}

void ServerExplorer::setupFileListView()
{
    m_fileListView->setModel(m_fileSysModel);
    m_fileListView->setRootIndex(m_fileSysModel->index(""));
    m_fileListView->setModelColumn(0);
    m_fileListView->setHorizontalScrollBar(m_scrollList);
    m_fileListView->setContextMenuPolicy(Qt::CustomContextMenu); //会发射customContextMenuRequested信号

}

void ServerExplorer::allConnect()
{
    //点击目录树，设置文件列表
    connect(m_treeView, SIGNAL(pressed(const QModelIndex &)),
            this, SLOT(pressOnTreeView(const QModelIndex &)));
    //点击列表，设置目录树
    connect(m_fileListView, SIGNAL(clicked(const QModelIndex &)),
            this, SLOT(clkOnFileList(const QModelIndex &)));
    //双击列表，打开目录树
    connect(m_fileListView, SIGNAL(doubleClicked(const QModelIndex &)),
            this, SLOT(doubleClkOnFileList(const QModelIndex &)));

    connect(m_fileListView, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(popMenuRequested(const QPoint &)));

    connect(m_transButton, SIGNAL(clicked()),
            this, SLOT(clkOnTransButton()));

}

void ServerExplorer::pressOnTreeView(const QModelIndex & index)
{
    if(m_fileSysModel->isDir(index))
    {
        m_fileListView->setRootIndex(index);
    }
}

void ServerExplorer::clkOnFileList(const QModelIndex &index)
{
    if(m_fileSysModel->isDir(index))
    {
        m_treeView->setCurrentIndex(index);
    }
}

void ServerExplorer::doubleClkOnFileList(const QModelIndex & index)
{
    if(m_fileSysModel->isDir(index))
    {
        m_fileListView->setRootIndex(index);
    }
    else
    {
        QString qfilePath("\"");
        qfilePath.append(m_fileSysModel->fileInfo(index).absoluteFilePath());
        qfilePath.append("\"");
        if ( ! QDesktopServices::openUrl(QUrl(qfilePath)) )
        {
            QMessageBox::information(this, tr("提示"), tr("没有相关联的程序打开此文件"),
                                     QMessageBox::Cancel);
        }

    }

}


void ServerExplorer::popMenuRequested(const QPoint &point)
{
    QMenu *m_popMenuFileList;
    QAction *m_addToTransAction;
    QAction *m_openAction;
    QAction *m_renameFileAction;
    QAction *m_delFileAction;

    m_popMenuFileList = new QMenu(this);
    m_addToTransAction = new QAction(tr("添加至传送列表"),this);
    m_openAction = new QAction(tr("打开"), this);
    m_renameFileAction = new QAction(tr("重命名"), this);
    m_delFileAction = new QAction(tr("删除"),this);


    m_popMenuFileList->addAction(m_addToTransAction);
    m_popMenuFileList->addSeparator();
    m_popMenuFileList->addAction(m_openAction);
    m_popMenuFileList->addAction(m_renameFileAction);
    m_popMenuFileList->addAction(m_delFileAction);

    if(m_fileSysModel->isDir(m_fileListView->indexAt(point)))
    {
        m_addToTransAction->setEnabled(false);
    }

    connect(m_addToTransAction, SIGNAL(triggered()),
            this, SLOT(addToTransList()));
    connect(m_openAction, SIGNAL(triggered()),
            this, SLOT(openFileOrDir()));
    connect(m_renameFileAction, SIGNAL(triggered()),
            this, SLOT(renameFile()));
    connect(m_delFileAction, SIGNAL(triggered()),
            this, SLOT(delFile()));

    m_popMenuFileList->exec(QCursor::pos());

    delete m_addToTransAction;
    delete m_renameFileAction;
    delete m_delFileAction;
    delete m_popMenuFileList;
}

void ServerExplorer::addToTransList()
{
    QModelIndex nowIndex = m_fileListView->currentIndex();
    QFileInfo nowFileInfo = m_fileSysModel->fileInfo(nowIndex);

    //显示在列表中
    QString addPathStr("\"");
    addPathStr.append(nowFileInfo.absoluteFilePath());
    addPathStr.append("\"");
    m_transList->addItem(addPathStr);

    //添加到发送列表
    m_transFileInfoList.append(nowFileInfo);
}

void ServerExplorer::openFileOrDir()
{
    QModelIndex index = m_fileListView->currentIndex();
    doubleClkOnFileList(index); //打开和双击的行为一样的
}

void ServerExplorer::renameFile()
{

}

void ServerExplorer::delFile()
{
    QModelIndex nowIndex = m_fileListView->currentIndex();
    if(m_fileSysModel->isDir(nowIndex))
    {
        QString text(tr("确认要删除文件夹\n"));
        text.append(m_fileSysModel->fileName(nowIndex));
        text.append(tr("\n么？"));
        if( QMessageBox::Yes ==
            QMessageBox::question(this, tr("确认"), text,
                                  QMessageBox::Yes, QMessageBox::Cancel)
            )
        {
            //不准删除系统目录
            if(isSystemDir(m_fileSysModel->filePath(nowIndex)))
            {
                QMessageBox::critical(this, tr("错误"), tr("系统文件不允许删除"));
                return ;
            }
            else
            {
                //预存父目录项
                QModelIndex parent = nowIndex.parent();
                if( ! m_fileSysModel->rmdir(m_fileListView->currentIndex()))
                {
                    QMessageBox::critical(this, tr("错误"), tr("删除失败，请检查权限"),
                                          QMessageBox::Cancel);
                    return ;
                }
                else
                {
                    m_treeView->setRootIndex(parent);
                }
            }

        }
    }
    else
    {
        QString text(tr("确认要删除\n"));
        text.append(m_fileSysModel->fileName(nowIndex));
        text.append(tr("\n么？"));
        if( QMessageBox::Yes ==
            QMessageBox::question(this, tr("确认"), text,
                                  QMessageBox::Yes, QMessageBox::Cancel)
            )
        {
            if( ! m_fileSysModel->remove(nowIndex))
            {
                QMessageBox::critical(this, tr("错误"), tr("删除失败，请检查权限"),
                                      QMessageBox::Cancel);
                return ;
            }
        }
    }
}


void ServerExplorer::clkOnTransButton()
{

}
