#include "serverexplorer.h"

ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    QStringList parameter;
    parameter.append(tr("服务器"));
    parameter.append(tr("发送到服务器"));
    setSpecificText(parameter);
}

ServerExplorer::~ServerExplorer()
{

}
