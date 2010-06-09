#include "serverexplorer.h"

ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setServerSpecificText(); //����һЩ�ؼ�����ʾ����
}

ServerExplorer::~ServerExplorer()
{

}

void ServerExplorer::setServerSpecificText()
{
    QStringList parameter;
    parameter.append(tr("������"));
    parameter.append(tr("���͵�������"));
    setSpecificText(parameter);
}

void ServerExplorer::InitTreeView()
{

}
