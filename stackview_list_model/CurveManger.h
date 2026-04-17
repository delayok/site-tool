#ifndef CURVEMANGER_H
#define CURVEMANGER_H

#include <QObject>
#include <QVector>
#include <QSharedPointer>
#include <QMap>
#include <QString>
#include <QVariantList>
#include "mapTableModel.h"

class CurveEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList dataVec READ dataVec NOTIFY dataVecChanged)
    Q_PROPERTY(float minY READ minY NOTIFY rangeChanged)
    Q_PROPERTY(float maxY READ maxY NOTIFY rangeChanged)
public:
    explicit CurveEntity(QObject *parent = nullptr) : QObject(parent) {}

    QVariantList dataVec() const {
        QVariantList list;
        for (float v : m_dataVec) {
            list.append(QVariant(v));
        }
        return list;
    }

    Q_INVOKABLE void addIncrese(float increse){
        m_dataVec.append(increse);
        emit dataVecChanged();

        auto iter = std::minmax_element(m_dataVec.begin(),m_dataVec.end());
        float minYtemp = *iter.first;
        float maxYtemp = *iter.second;
    }

    Q_INVOKABLE void clear() {
        m_dataVec.clear();
        emit dataVecChanged();
    }

    float maxY(){return  m_maxY;}
    float minY(){return  m_minY;}

signals:
    void rangeChanged();
    void dataVecChanged();

public:
    float m_minY {-10.0};
    float m_maxY {10.0};
    QString  code;
    QVector<float> m_dataVec;
};

class CurveManger : public QObject
{
    Q_OBJECT
public:
    explicit CurveManger(QObject *parent = nullptr);

    Q_INVOKABLE void addCurve(QString code){
        if (!m_mapModel.contains(code))
        {
            m_mapModel.insert(code, QSharedPointer<MapTableModel>(new MapTableModel(this)));
        }
    }

    Q_INVOKABLE void remove(QString code)
    {
        if (m_mapModel.contains(code))
        {
            m_mapModel.remove(code);
        }
    }

    Q_INVOKABLE void addData(QString code , float increase){
        if (m_mapModel.contains(code))
        {
            m_mapModel.value(code).data()->add(increase);
        }
    }

    Q_INVOKABLE MapTableModel* getCurveModel(QString code) {
        if (m_mapModel.contains(code)) {
            MapTableModel* data =  m_mapModel.value(code).get();
            return data;
        }
        return nullptr;
    }

private:
    QMap<QString,QSharedPointer<MapTableModel>> m_mapModel;


};

#endif // CURVEMANGER_H
