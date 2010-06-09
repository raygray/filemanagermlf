#include "baseexplorer.h"

BaseExplorer::BaseExplorer(QWidget *parent) :
    QWidget(parent)
{
    createWidgets();
    setupWidgets();
}

BaseExplorer::~BaseExplorer()
{
}

void BaseExplorer::createWidgets()
{
    m_splitter = new QSplitter(this);
    m_splitter->setOrientation(Qt::Horizontal);
    m_splitter->setStretchFactor(2, 1);

    m_splitter->setChildrenCollapsible(false); //����������Сʱ������
    m_treeView = new QTreeWidget(this);
    m_fileList = new QListWidget(this);
    m_transList = new QListWidget(this);

    m_horizontalLayout = new QHBoxLayout(this);
    m_sizeOfWidgetsInSplitter << 200 << 400 << 200; //��QList��ֵ

    //����Ŀ¼�������
    m_vBoxLayoutOfTreeView = new QVBoxLayout(this);
    m_treeViewFrame = new QFrame(this);
    m_typeLabel = new QLabel(this);

    //�ļ��б����
    m_vBoxLayoutOfFileList = new QVBoxLayout(this);
    m_transListFrame = new QFrame(this);
    m_fileListFrame = new QFrame(this);


    //�����б������
    m_vBoxLayoutOfTransList = new QVBoxLayout(this);
    m_hBoxLayoutOfTransList = new QHBoxLayout(this);
    m_transListFrame = new QFrame(this);
    m_selectAllCheckBox = new QCheckBox(this);
    m_delButton = new QPushButton(tr("ɾ��"), this);
    m_transButton = new QPushButton(this);


}

void BaseExplorer::setupWidgets()
{
    //Ŀ¼������
    m_vBoxLayoutOfTreeView->addWidget(m_typeLabel);
    m_vBoxLayoutOfTreeView->addWidget(m_treeView);
    m_treeViewFrame->setLayout(m_vBoxLayoutOfTreeView);
    m_splitter->addWidget(m_treeViewFrame);

    //�ļ��б���
    //m_vBoxLayoutOfFileList->addWidget(XXX);
    m_vBoxLayoutOfFileList->addWidget(m_fileList);
    m_fileListFrame->setLayout(m_vBoxLayoutOfFileList);
    m_splitter->addWidget(m_fileListFrame);

    //�����б���
    m_hBoxLayoutOfTransList->addWidget(m_selectAllCheckBox);
    m_hBoxLayoutOfTransList->addWidget(m_delButton);
    m_hBoxLayoutOfTransList->addWidget(m_transButton);

    m_vBoxLayoutOfTransList->addWidget(m_transList);
    m_vBoxLayoutOfTransList->addLayout(m_hBoxLayoutOfTransList);

    m_transListFrame->setLayout(m_vBoxLayoutOfTransList);
    m_splitter->addWidget(m_transListFrame);

    //һЩ����
    m_splitter->setSizes(m_sizeOfWidgetsInSplitter); //���ÿؼ���ʼ��С
    m_horizontalLayout->addWidget(m_splitter);
    this->setLayout(m_horizontalLayout);

}

void BaseExplorer::restoreWindowSize()
{
    m_sizeOfWidgetsInSplitter.clear();
    m_sizeOfWidgetsInSplitter << 200 << 400 << 200;
    m_splitter->setSizes(m_sizeOfWidgetsInSplitter);
}

void BaseExplorer::setSpecificText(const Parameter &parameter)
{
    m_typeLabel->setText(parameter.textType());
    m_transButton->setText(parameter.textTransButton());
}
