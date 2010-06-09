#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QLabel>
#include <QSplitter>
#include <QHBoxLayout>

#include "baseexplorer.h"
#include "clientexplorer.h"
#include "serverexplorer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();   //创建菜单项
    void createMenus();     //创建目录
    void createStatusBar(); //创建状态栏
    void createWidgets();   //创建其他控件
    void setupWidgets();    //设置控件

private slots:
    void exit();
    void about();


private:
    //菜单栏项
    QMenu *m_fileMenu;
    QMenu *m_fileManagerMenu;
    QMenu *m_fileTransmissionMenu;
    QMenu *m_helpMenu;

    //菜单项
    QAction *m_exitAction;

    QAction *m_renameAction;
    QAction *m_delAction;

    QAction *m_transFromClientToServerAction;
    QAction *m_transFromServerToClientAction;

    QAction *m_aboutAction;

    QLabel *m_commandTip;//任务栏中提示Label

    QSplitter *m_splitterMain; //划分为上下两部分

    //文件管理窗口
    BaseExplorer *clientExplorer;
    BaseExplorer *serverExplorer;
};

#endif // MAINWINDOW_H
