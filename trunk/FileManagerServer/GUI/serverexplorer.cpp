#include "serverexplorer.h"
#include <QLocale>

ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setServerSpecificText(); //设置一些控件的显示文字
    createModel();
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
    paraMap.insert("transButton", tr("发送到服务器"));
    paraMap.insert("currentPathLabel", tr("<font color = green>路径</font>"));
    Parameter parameter(paraMap);
    setSpecificText(parameter);
}

void ServerExplorer::createModel()
{
    m_fileSysModel = new QFileSystemModel(this);
    m_fileSysModel->setRootPath("");
    //m_fileSysModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
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

}

void ServerExplorer::allConnect()
{
    //点击目录树，设置文件列表
    connect(m_treeView, SIGNAL(clicked(const QModelIndex &)),
            m_fileListView, SLOT(setRootIndex(const QModelIndex &)));
    //点击列表，设置目录树
    connect(m_fileListView, SIGNAL(clicked(const QModelIndex &)),
            m_treeView, SLOT(setCurrentIndex(const QModelIndex &)));
    //双击列表，打开目录树
    connect(m_fileListView, SIGNAL(doubleClicked(const QModelIndex &)),
            m_fileListView, SLOT(setRootIndex(const QModelIndex &)));


}
