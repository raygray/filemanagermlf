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
    void restoreWindowSize(); //���ò���
    void setSpecificText(const Parameter &parameter); //���þ���ĵ�Text

signals:

public slots:

protected:
    //main widget
    QSplitter *m_splitter;
    QTreeView *m_treeView; //����Ŀ¼��
    QListView *m_fileListView; //�ļ��б�
    QListWidget *m_transList;//�����б�
    QHBoxLayout *m_horizontalLayout; //ˮƽ���֣�����Ӧ���
    QList<int> m_sizeOfWidgetsInSplitter; //�ؼ���ʼ��С

    //����Ŀ¼��һЩ���ֺͿؼ�
    QVBoxLayout *m_vBoxLayoutOfTreeView;
    QLabel *m_typeLabel;
    QFrame *m_treeViewFrame;

    //�ļ��б��һЩ���ֺͿؼ�
    QVBoxLayout *m_vBoxLayoutOfFileList;
    QFrame *m_fileListFrame;
    QHBoxLayout *m_hBoxLayoutOfFileList;
    QLabel *m_currentPathLabel;
    QLineEdit *m_currentPathLineEdit;

    //�����б��һЩ���ֺͿؼ�
    QVBoxLayout *m_vBoxLayoutOfTransList; //�����б��е��Ӵ�ֱ����
    QHBoxLayout *m_hBoxLayoutOfTransList; //�����б��е���ˮƽ����
    QFrame *m_transListFrame;
    QCheckBox *m_selectAllCheckBox;
    QPushButton *m_delButton;
    QPushButton *m_transButton;



};

#endif // BASEEXPLORER_H
