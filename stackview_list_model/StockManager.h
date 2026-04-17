#ifndef STOCKMANAGER_H
#define STOCKMANAGER_H

#include <QObject>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QTextCodec>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "stockModel.h"
#include "CurveManger.h"
#include "setting.h"

class StockManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString curcode READ curcode WRITE setcurcode NOTIFY curcodeChanged)
    Q_PROPERTY(QAbstractListModel* model READ getModel CONSTANT)
    Q_PROPERTY(QList<QString> codelist READ codelist)
    Q_PROPERTY(QString codeName READ codeName WRITE setcodeName)

public:

    explicit StockManager(QObject *parent = nullptr);
    ~StockManager();

    QList<QString> codelist(){
        return m_codelist;
    }
    void setcurcode(QString code){
        bool isint;
        code.toInt(&isint);
        if (!isint)
        {
            setcodeName(code);
            return;
        }

        if (code == m_curcode)
            return;
        if (!m_codelist.contains(code))
        {
            m_codelist.append(code);
            m_curveMgr->addCurve(code);
            emit curcodeChanged(code);
        }
    }
    QString curcode(){
        return m_curcode;
    }
    Q_INVOKABLE void removecodelist(QString code){
        if (m_codelist.contains(code))
        {
            m_codelist.removeAt(m_codelist.indexOf(code));
            m_curveMgr->remove(code);
            if (m_codelist.count() == 0)
                m_model->setDataList(QList<stockModel::JsonPkg>());
        }
    }
    Q_INVOKABLE stockModel* getModel(){return  m_model;};
    Q_INVOKABLE MapTableModel* getXYtableModel(const QString &code){return m_curveMgr->getCurveModel(code);};
    Q_INVOKABLE void save() {m_setting->saveCodels(m_codelist);}

    QString codeName(){return m_codeName;}
    void setcodeName(QString name ){
       m_codeName = name;
       QString url = QString("https://searchapi.eastmoney.com/api/suggest/get?input=%1&type=14&count=10").arg(m_codeName);
       QString url2 = QString("https://smartbox.gtimg.cn/s3/?q=%1&t=all").arg(m_codeName);

       m_managerName.get(QNetworkRequest(QUrl(url2)));
    };

    Q_INVOKABLE void setViable(QString code){
        bool visable =false;
        if (m_isvisable.contains(code))
            visable = !m_isvisable.value(code);
       m_isvisable.insert(code,visable);
    };
    Q_INVOKABLE bool getCodeVisable(QString code){
       if (m_isvisable.contains(code))
           return m_isvisable.value(code);
       return true;
    };

public slots:
    void onRequestUrl();
    void onReplyFinished(QNetworkReply *reply);
    void onReplyFinishedName(QNetworkReply *reply);
    void onStart();


signals:
    void curcodeChanged(QString code);
    void jsonUpdated(stockModel::JsonPkg da);
private:
    QList<QString> m_codelist;
    QString m_curcode;
    QTimer * m_timer;
    QNetworkAccessManager m_mager;
    QNetworkAccessManager m_managerName;
    stockModel *m_model;
    QString m_codeName;
    CurveManger *m_curveMgr;
    QMap<QString,bool> m_isvisable;
    setting* m_setting;

};

#endif // STOCKMANAGER_H
