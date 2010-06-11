#include "clientexplorer.h"

ClientExplorer::ClientExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setClientSpecificText(); //����һЩ�ؼ�����ʾ����
}

ClientExplorer::~ClientExplorer()
{

}

void ClientExplorer::setClientSpecificText()
{
    QMap<QString, QString> paraMap;
    paraMap.insert("typeLabel", tr("<font color = red>�ͻ���</font>"));
    paraMap.insert("transButton", tr("�ϴ���������"));
    paraMap.insert("currentPathLabel", tr("<font color = red>·��</font>"));
    Parameter parameter(paraMap);
    setSpecificText(parameter);
}

void ClientExplorer::InitTreeView()
{
}
