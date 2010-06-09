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
    void createActions();   //�����˵���
    void createMenus();     //����Ŀ¼
    void createStatusBar(); //����״̬��
    void createWidgets();   //���������ؼ�
    void setupWidgets();    //���ÿؼ�

private slots:
    void exit();
    void about();


private:
    //�˵�����
    QMenu *m_fileMenu;
    QMenu *m_fileManagerMenu;
    QMenu *m_fileTransmissionMenu;
    QMenu *m_helpMenu;

    //�˵���
    QAction *m_exitAction;

    QAction *m_renameAction;
    QAction *m_delAction;

    QAction *m_transFromClientToServerAction;
    QAction *m_transFromServerToClientAction;

    QAction *m_aboutAction;

    QLabel *m_commandTip;//����������ʾLabel

    QSplitter *m_splitterMain; //����Ϊ����������

    //�ļ�������
    BaseExplorer *clientExplorer;
    BaseExplorer *serverExplorer;
};

#endif // MAINWINDOW_H
