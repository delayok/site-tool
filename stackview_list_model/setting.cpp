#include "setting.h"

setting::setting(QObject* parent )
    :QObject(parent)
{
    m_setings = new QSettings("./configguguggu.ini",QSettings::IniFormat);
    m_curlist = m_setings->value("codelist","").toString();
}
