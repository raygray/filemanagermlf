#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>
#include <QStringList>
#include <QMap>

class Parameter
{
public:
    Parameter();
    Parameter(QMap<QString, QString> paraMap);

    ~Parameter();

public:
    QString getValueOf(const QString key) const;

private:
    QMap<QString, QString> m_paraMap;
};

#endif // PARAMETER_H
