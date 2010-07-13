#include "serverexplorer.h"
#include <QLocale>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

#include "common.h"



ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setServerSpecificText(); //����һЩ�ؼ�����ʾ����
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
    paraMap.insert("typeLabel", tr("<font color = green>������</font>"));
    paraMap.insert("transButton", tr("���͵��ͻ���"));
    paraMap.insert("currentPathLabel", tr("<font color = green>·��</font>"));
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
    m_fileListView->setContextMenuPolicy(Qt::CustomContextMenu); //�ᷢ��customContextMenuRequested�ź�

}

void ServerExplorer::allConnect()
{
    //���Ŀ¼���������ļ��б�
    connect(m_treeView, SIGNAL(pressed(const QModelIndex &)),
            this, SLOT(pressOnTreeView(const QModelIndex &)));
    //����б�����Ŀ¼��
    connect(m_fileListView, SIGNAL(clicked(const QModelIndex &)),
            this, SLOT(clkOnFileList(const QModelIndex &)));
    //˫���б���Ŀ¼��
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
            QMessageBox::information(this, tr("��ʾ"), tr("û��������ĳ���򿪴��ļ�"),
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
    m_addToTransAction = new QAction(tr("����������б�"),this);
    m_openAction = new QAction(tr("��"), this);
    m_renameFileAction = new QAction(tr("������"), this);
    m_delFileAction = new QAction(tr("ɾ��"),this);


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

    //��ʾ���б���
    QString addPathStr("\"");
    addPathStr.append(nowFileInfo.absoluteFilePath());
    addPathStr.append("\"");
    m_transList->addItem(addPathStr);

    //��ӵ������б�
    m_transFileInfoList.append(nowFileInfo);
}

void ServerExplorer::openFileOrDir()
{
    QModelIndex index = m_fileListView->currentIndex();
    doubleClkOnFileList(index); //�򿪺�˫������Ϊһ����
}

void ServerExplorer::renameFile()
{

}

void ServerExplorer::delFile()
{
    QModelIndex nowIndex = m_fileListView->currentIndex();
    if(m_fileSysModel->isDir(nowIndex))
    {
        QString text(tr("ȷ��Ҫɾ���ļ���\n"));
        text.append(m_fileSysModel->fileName(nowIndex));
        text.append(tr("\nô��"));
        if( QMessageBox::Yes ==
            QMessageBox::question(this, tr("ȷ��"), text,
                                  QMessageBox::Yes, QMessageBox::Cancel)
            )
        {
            //��׼ɾ��ϵͳĿ¼
            if(isSystemDir(m_fileSysModel->filePath(nowIndex)))
            {
                QMessageBox::critical(this, tr("����"), tr("ϵͳ�ļ�������ɾ��"));
                return ;
            }
            else
            {
                //Ԥ�游Ŀ¼��
                QModelIndex parent = nowIndex.parent();
                if( ! m_fileSysModel->rmdir(m_fileListView->currentIndex()))
                {
                    QMessageBox::critical(this, tr("����"), tr("ɾ��ʧ�ܣ�����Ȩ��"),
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
        QString text(tr("ȷ��Ҫɾ��\n"));
        text.append(m_fileSysModel->fileName(nowIndex));
        text.append(tr("\nô��"));
        if( QMessageBox::Yes ==
            QMessageBox::question(this, tr("ȷ��"), text,
                                  QMessageBox::Yes, QMessageBox::Cancel)
            )
        {
            if( ! m_fileSysModel->remove(nowIndex))
            {
                QMessageBox::critical(this, tr("����"), tr("ɾ��ʧ�ܣ�����Ȩ��"),
                                      QMessageBox::Cancel);
                return ;
            }
        }
    }
}


void ServerExplorer::clkOnTransButton()
{

}
