#ifndef STOCKPRICEFETCHER_H
#define STOCKPRICEFETCHER_H

#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QTimer>

class StockPriceFetcher : public QObject
{
    Q_OBJECT
public:

    enum {
        E_EAST_FU = 0,
        E_TENGXUN,
        E_MAX
    };
    struct JsonPkg{
        QString name;
        double price;
        double mhmov;//分时均线值
        double open;
        double increase;
    };
    explicit StockPriceFetcher(QObject *parent = nullptr);

    void setStockCode(const QString &code);
    void start(int intervalMs = 1000);
    void stop();
    void setStockName(const QString &name){
        m_stockName = name;
        searchName();
        };
    QString searchName();
    void setUrlType(int index){m_urlType =index; };

signals:
    void priceUpdated(double price);
    void jsonUpdated(const JsonPkg &price);
    void jsonNameUpdated(const QString& name);

private slots:
    void requestPrice();
    void onReplyFinished(QNetworkReply *reply);
    void onReplyFinishedName(QNetworkReply *reply);

private:
    QString m_stockCode;
    QNetworkAccessManager m_manager;
    QNetworkAccessManager m_managerName;
    QTimer m_timer;
    QString m_stockName;
    int m_urlType{E_EAST_FU};
};


#endif // STOCKPRICEFETCHER_H
