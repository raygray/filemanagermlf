#include "clientexplorer.h"

ClientExplorer::ClientExplorer(BaseExplorer *baseExplorer)
    :BaseExplorer(baseExplorer)
{
    QStringList parameter;
    parameter.append(tr("�ͻ���"));
    parameter.append(tr("�ϴ���������"));
    setSpecificText(parameter);
}

ClientExplorer::~ClientExplorer()
{

}
