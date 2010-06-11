#include "parameter.h"

Parameter::Parameter()
{
}

Parameter::Parameter(QMap<QString, QString> paraMap)
    :m_paraMap(paraMap)
{

}

Parameter::~Parameter()
{

}

QString Parameter::getValueOf(const QString key) const
{
    return m_paraMap.value(key);
}


//Parameter::Parameter(
//        QString textType,
//        QString textTransButton,
//        QString currentPath
//        ):
//        m_textType(textType),
//        m_textTransButton(textTransButton),
//        m_textCurrentPath(currentPath)
//{
//}
//
//Parameter::Parameter(QStringList allText)
//{
//    m_textType = allText[0];
//    m_textTransButton = allText[1];
//    m_textCurrentPath = allText[2];
//}


//QString Parameter::textType() const
//{
//    return m_textType;
//}
//
//QString Parameter::textTransButton() const
//{
//    return m_textTransButton;
//}
//
//QString Parameter::textCurrentPath() const
//{
//    return m_textCurrentPath;
//}
