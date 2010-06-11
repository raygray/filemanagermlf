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
    m_treeView = new QTreeView(this);
    m_fileListView = new QListView(this);
    m_transList = new QListWidget(this);

    m_horizontalLayout = new QHBoxLayout(this);
    m_horizontalLayout->setContentsMargins(4, 8, 4, 0);

    m_sizeOfWidgetsInSplitter << 200 << 400 << 200; //��QList��ֵ

    //����Ŀ¼�������
    m_vBoxLayoutOfTreeView = new QVBoxLayout(this);
    m_vBoxLayoutOfTreeView->setContentsMargins(0, 0, 0, 0);
    m_treeViewFrame = new QFrame(this);
    m_typeLabel = new QLabel(this);

    //�ļ��б����
    m_vBoxLayoutOfFileList = new QVBoxLayout(this);
    m_vBoxLayoutOfFileList->setContentsMargins(0, 0, 0, 0);
    m_hBoxLayoutOfFileList = new QHBoxLayout(this);
    m_hBoxLayoutOfFileList->setContentsMargins(0, 0, 0, 0);

    m_fileListFrame = new QFrame(this);
    m_currentPathLabel = new QLabel(this);
    m_currentPathLineEdit = new QLineEdit(this);


    //�����б������
    m_vBoxLayoutOfTransList = new QVBoxLayout(this);
    m_vBoxLayoutOfTransList->setContentsMargins(0,0, 0, 0);

    m_hBoxLayoutOfTransList = new QHBoxLayout(this);
    m_hBoxLayoutOfTransList->setContentsMargins(0,0,0,0);
    m_transListFrame = new QFrame(this);
    m_selectAllCheckBox = new QCheckBox(tr("����"), this);
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
    m_hBoxLayoutOfFileList->addWidget(m_currentPathLabel);
    m_hBoxLayoutOfFileList->addWidget(m_currentPathLineEdit);

    m_vBoxLayoutOfFileList->addLayout(m_hBoxLayoutOfFileList);
    m_vBoxLayoutOfFileList->addWidget(m_fileListView);

    m_fileListFrame->setLayout(m_vBoxLayoutOfFileList);
    m_splitter->addWidget(m_fileListFrame);


    //�����б���
    m_hBoxLayoutOfTransList->addWidget(m_selectAllCheckBox);
    m_hBoxLayoutOfTransList->addWidget(m_delButton);
    m_hBoxLayoutOfTransList->addWidget(m_transButton);

    m_vBoxLayoutOfTransList->addLayout(m_hBoxLayoutOfTransList);
    m_vBoxLayoutOfTransList->addWidget(m_transList);

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
    //���ݲ�ͬ�Ĳ���������ť��Label����������ʾText
    m_typeLabel->setText(parameter.getValueOf("typeLabel"));
    m_transButton->setText(parameter.getValueOf("transButton"));
    m_currentPathLabel->setText(parameter.getValueOf("currentPathLabel"));

}
