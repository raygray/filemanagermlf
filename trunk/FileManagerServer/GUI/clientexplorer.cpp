#include "clientexplorer.h"

ClientExplorer::ClientExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    QStringList parameter;
    parameter.append(tr("客户端"));
    parameter.append(tr("上传至服务器"));
    setSpecificText(parameter);
}

ClientExplorer::~ClientExplorer()
{

}
