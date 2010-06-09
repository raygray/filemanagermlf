#include "serverexplorer.h"

ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setServerSpecificText(); //设置一些控件的显示文字
}

ServerExplorer::~ServerExplorer()
{

}

void ServerExplorer::setServerSpecificText()
{
    QStringList parameter;
    parameter.append(tr("服务器"));
    parameter.append(tr("发送到服务器"));
    setSpecificText(parameter);
}

void ServerExplorer::InitTreeView()
{

}
