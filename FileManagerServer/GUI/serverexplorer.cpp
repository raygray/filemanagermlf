#include "serverexplorer.h"

ServerExplorer::ServerExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    QStringList parameter;
    parameter.append(tr("������"));
    parameter.append(tr("���͵�������"));
    setSpecificText(parameter);
}

ServerExplorer::~ServerExplorer()
{

}
