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
    QMap<QString, QString> paraMap;
    paraMap.insert("typeLabel", tr("<font color = red>客户端</font>"));
    paraMap.insert("transButton", tr("上传至服务器"));
    paraMap.insert("currentPathLabel", tr("<font color = red>路径</font>"));
    Parameter parameter(paraMap);
    setSpecificText(parameter);
}

void ClientExplorer::InitTreeView()
{
}
