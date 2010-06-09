#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>
#include <QStringList>

class Parameter
{
public:
    Parameter();
    Parameter(QString textType, QString textTransButton);
    Parameter(QStringList allText);
    ~Parameter();

public:
    QString textType() const;
    QString textTransButton() const;

private:
    QString m_textType;
    QString m_textTransButton;

};

#endif // PARAMETER_H
