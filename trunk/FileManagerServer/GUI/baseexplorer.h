#ifndef BASEEXPLORER_H
#define BASEEXPLORER_H

#include <QWidget>
#include <QSplitter>
#include <QTreeWidget>
#include <QTreeView>
#include <QListView>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QFrame>
#include <QMargins>
#include <QLineEdit>

#include "parameter.h"

class BaseExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit BaseExplorer(QWidget *parent = 0);
    virtual ~BaseExplorer();
private:
    void createWidgets();
    void setupWidgets();

public:
    void restoreWindowSize(); //重置布局
    void setSpecificText(const Parameter &parameter); //设置具体的的Text

signals:

public slots:

protected:
    //main widget
    QSplitter *m_splitter;
    QTreeView *m_treeView; //磁盘目录树
    QListView *m_fileListView; //文件列表
    QListWidget *m_transList;//传输列表
    QHBoxLayout *m_horizontalLayout; //水平布局，自适应填充
    QList<int> m_sizeOfWidgetsInSplitter; //控件初始大小

    //磁盘目录的一些布局和控件
    QVBoxLayout *m_vBoxLayoutOfTreeView;
    QLabel *m_typeLabel;
    QFrame *m_treeViewFrame;

    //文件列表的一些布局和控件
    QVBoxLayout *m_vBoxLayoutOfFileList;
    QFrame *m_fileListFrame;
    QHBoxLayout *m_hBoxLayoutOfFileList;
    QLabel *m_currentPathLabel;
    QLineEdit *m_currentPathLineEdit;

    //传输列表的一些布局和控件
    QVBoxLayout *m_vBoxLayoutOfTransList; //传输列表中的子垂直布局
    QHBoxLayout *m_hBoxLayoutOfTransList; //传输列表中的子水平布局
    QFrame *m_transListFrame;
    QCheckBox *m_selectAllCheckBox;
    QPushButton *m_delButton;
    QPushButton *m_transButton;



};

#endif // BASEEXPLORER_H
