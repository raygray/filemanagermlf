#include "parameter.h"

Parameter::Parameter()
{
}

Parameter::Parameter(QString textType, QString textTransButton)
    :m_textType(textType), m_textTransButton(textTransButton)
{
}

Parameter::Parameter(QStringList allText)
{
    m_textType = allText[0];
    m_textTransButton = allText[1];
}

Parameter::~Parameter()
{

}

QString Parameter::textType() const
{
    return m_textType;
}

QString Parameter::textTransButton() const
{
    return m_textTransButton;
}
