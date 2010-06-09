#include "clientexplorer.h"

ClientExplorer::ClientExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    setClientSpecificText(); //设置一些控件的显示文字
}

ClientExplorer::~ClientExplorer()
{

}

void ClientExplorer::setClientSpecificText()
{
    QStringList parameter;
    parameter.append(tr("客户端"));
    parameter.append(tr("上传至服务器"));
    setSpecificText(parameter);
}

void ClientExplorer::InitTreeView()
{

}
