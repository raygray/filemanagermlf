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
    QStringList parameter;
    parameter.append(tr("�ͻ���"));
    parameter.append(tr("�ϴ���������"));
    setSpecificText(parameter);
}

void ClientExplorer::InitTreeView()
{

}
