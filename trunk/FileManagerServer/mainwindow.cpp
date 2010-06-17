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
    m_exitAction = new QAction(tr("退出"),this);
    m_exitAction->setStatusTip(tr("退出程序"));
    connect(m_exitAction, SIGNAL(triggered()), this, SLOT(exit()));

    m_renameAction = new QAction(tr("重命名"), this);
    m_renameAction->setStatusTip(tr("重命名文件"));
    m_delAction = new QAction(tr("删除文件"), this);
    m_delAction->setStatusTip(tr("删除文件"));

    m_transFromClientToServerAction = new QAction(tr("客户端到服务器"),this);
    m_transFromClientToServerAction->setStatusTip(tr("将文件从客户端上传到服务器端"));
    m_transFromServerToClientAction = new QAction(tr("服务器到客户端"),this);
    m_transFromServerToClientAction->setStatusTip(tr("将文件从服务器端发送到客户端"));

    m_aboutAction = new QAction(tr("关于"), this);
    m_aboutAction->setStatusTip(tr("关于本程序"));

    connect(m_aboutAction, SIGNAL(triggered()), this, SLOT(about()));

}

void MainWindow::createMenus()
{
    // 添加菜单栏项
    m_fileMenu = menuBar()->addMenu(tr("文件"));
    m_fileManagerMenu = menuBar()->addMenu(tr("文件管理"));
    m_fileTransmissionMenu = menuBar()->addMenu(tr("文件传输"));
    m_helpMenu = menuBar()->addMenu(tr("帮助"));

    // 添加菜单项
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
    m_splitterMain->setChildrenCollapsible(false); //设置拉到最小时不隐藏

    clientExplorer = new ClientExplorer();
    serverExplorer = new ServerExplorer();
}

void MainWindow::setupWidgets()
{
    //添加窗口分割的子窗口
    m_splitterMain->addWidget(clientExplorer);
    m_splitterMain->addWidget(serverExplorer);

    this->setCentralWidget(m_splitterMain); //设为中心容器

    this->setWindowTitle(tr("文件管理系统\\VHBLCD网络广告"));
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
    QMessageBox::about(this, tr("关于文件管理系统"), tr("VHBLCD网络广告\\文件管理系统"));
}
