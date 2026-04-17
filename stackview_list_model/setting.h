#ifndef SETTING_H
#define SETTING_H

#include <QObject>
#include <QSettings>

class setting : public QObject
{
    Q_OBJECT
public:
    setting(QObject* parent = nullptr);

    QList<QString> getCode(){

       QString ret =   m_setings->value(m_key,"").toString();
       QList<QString> r = ret.split(",");
       return r;
    }

    void addCode(QString CODE){
        m_curlist.append("," + CODE);
        m_setings->setValue(m_key,m_curlist);
    }
    void saveCodels(QList<QString> ls){
        QString re;
        for (auto t: ls)
        {
            re += t;
            if (t != ls.last())
                re += ",";
        }
        m_setings->setValue(m_key,re);
    }

private:
    QSettings *m_setings;
    QString m_curlist;
    QString m_key{"codelist"};
};

#endif // SETTING_H
