#include "serverexplorer.h"
#include <QLocale>

ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setServerSpecificText(); //����һЩ�ؼ�����ʾ����
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
    paraMap.insert("typeLabel", tr("<font color = green>������</font>"));
    paraMap.insert("transButton", tr("���͵�������"));
    paraMap.insert("currentPathLabel", tr("<font color = green>·��</font>"));
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
    //���Ŀ¼���������ļ��б�
    connect(m_treeView, SIGNAL(clicked(const QModelIndex &)),
            m_fileListView, SLOT(setRootIndex(const QModelIndex &)));
    //����б�����Ŀ¼��
    connect(m_fileListView, SIGNAL(clicked(const QModelIndex &)),
            m_treeView, SLOT(setCurrentIndex(const QModelIndex &)));
    //˫���б���Ŀ¼��
    connect(m_fileListView, SIGNAL(doubleClicked(const QModelIndex &)),
            m_fileListView, SLOT(setRootIndex(const QModelIndex &)));


}
