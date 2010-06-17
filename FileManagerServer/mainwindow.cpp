#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>


#include "commandserverthread.h"
#include "dataserverthread.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    createStatusBar();
    createWidgets();
    setupWidgets();

    startServers();

}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    m_exitAction = new QAction(tr("�˳�"),this);
    m_exitAction->setStatusTip(tr("�˳�����"));
    connect(m_exitAction, SIGNAL(triggered()), this, SLOT(exit()));

    m_renameAction = new QAction(tr("������"), this);
    m_renameAction->setStatusTip(tr("�������ļ�"));
    m_delAction = new QAction(tr("ɾ���ļ�"), this);
    m_delAction->setStatusTip(tr("ɾ���ļ�"));

    m_transFromClientToServerAction = new QAction(tr("�ͻ��˵�������"),this);
    m_transFromClientToServerAction->setStatusTip(tr("���ļ��ӿͻ����ϴ�����������"));
    m_transFromServerToClientAction = new QAction(tr("���������ͻ���"),this);
    m_transFromServerToClientAction->setStatusTip(tr("���ļ��ӷ������˷��͵��ͻ���"));

    m_aboutAction = new QAction(tr("����"), this);
    m_aboutAction->setStatusTip(tr("���ڱ�����"));

    connect(m_aboutAction, SIGNAL(triggered()), this, SLOT(about()));

}

void MainWindow::createMenus()
{
    // ��Ӳ˵�����
    m_fileMenu = menuBar()->addMenu(tr("�ļ�"));
    m_fileManagerMenu = menuBar()->addMenu(tr("�ļ�����"));
    m_fileTransmissionMenu = menuBar()->addMenu(tr("�ļ�����"));
    m_helpMenu = menuBar()->addMenu(tr("����"));

    // ��Ӳ˵���
    m_fileMenu->addAction(m_exitAction);

    m_fileManagerMenu->addAction(m_renameAction);
    m_fileManagerMenu->addSeparator();
    m_fileManagerMenu->addAction(m_delAction);

    m_fileTransmissionMenu->addAction(m_transFromClientToServerAction);
    m_fileTransmissionMenu->addSeparator();
    m_fileTransmissionMenu->addAction(m_transFromServerToClientAction);

    m_helpMenu->addAction(m_aboutAction);

}

void MainWindow::createStatusBar()
{
    m_commandTip = new QLabel(this);
    statusBar()->addWidget(m_commandTip, 1);
}

void MainWindow::createWidgets()
{
    m_splitterMain = new QSplitter(this);
    m_splitterMain->setOrientation(Qt::Vertical);
    m_splitterMain->setStretchFactor(1, 1);
    m_splitterMain->setChildrenCollapsible(false); //����������Сʱ������

    clientExplorer = new ClientExplorer();
    serverExplorer = new ServerExplorer();
}

void MainWindow::setupWidgets()
{
    //��Ӵ��ڷָ���Ӵ���
    m_splitterMain->addWidget(clientExplorer);
    m_splitterMain->addWidget(serverExplorer);

    this->setCentralWidget(m_splitterMain); //��Ϊ��������

    this->setWindowTitle(tr("�ļ�����ϵͳ\\VHBLCD������"));
    this->setMinimumSize(800,600);
    this->resize(1000,600);

}

void MainWindow::startServers()
{
    CommandServerThread::createServer();
    DataServerThread::createServer();
}

void MainWindow::exit()
{
    QApplication::exit(0);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("�����ļ�����ϵͳ"), tr("VHBLCD������\\�ļ�����ϵͳ"));
}
