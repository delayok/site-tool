#include "StockPriceFetcher.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextCodec>
#include <QDebug>
#include <QJsonArray>

StockPriceFetcher::StockPriceFetcher(QObject *parent)
    : QObject(parent)
{
    connect(&m_manager, &QNetworkAccessManager::finished,
            this, &StockPriceFetcher::onReplyFinished);

    connect(&m_timer, &QTimer::timeout,
            this, &StockPriceFetcher::requestPrice);

    connect(&m_managerName, &QNetworkAccessManager::finished,
            this, &StockPriceFetcher::onReplyFinishedName);

}

void StockPriceFetcher::setStockCode(const QString &code)
{
    m_stockCode = code;
}

void StockPriceFetcher::start(int intervalMs)
{
    m_timer.start(intervalMs);
    requestPrice();
}

void StockPriceFetcher::stop()
{
    m_timer.stop();
}

QString StockPriceFetcher::searchName()
{
    QString url = QString("https://searchapi.eastmoney.com/api/suggest/get?input=%1&type=14&count=10").arg(m_stockName);
    m_managerName.get(QNetworkRequest(QUrl(url)));
    return "";
}

void StockPriceFetcher::requestPrice()
{
    if (m_stockCode.isEmpty())
        return;

//    if (m_stockCode.startsWith("6"))
//        m_stockCode = "sh" + m_stockCode;
//    else
//        m_stockCode = "sz" + m_stockCode;

    QString secid = m_stockCode.trimmed();
    QString url;
    QString secid_1, secid_2;
    if (secid.startsWith("6")) {
        // sh
        secid_1 =  "1." + m_stockCode;//.rightJustified(8, '0')
        secid_2 = "s_sh" + m_stockCode;
    } else {
        // sz（000 / 002 / 300）
        secid_1 =  "0." + m_stockCode;
        secid_2 = "s_sz" + m_stockCode;
    }
    if (m_urlType == E_EAST_FU)
    {
       url  = QString("http://push2.eastmoney.com/api/qt/stock/get""?secid=%1&fields=f46,f57,f58,f43,f71,f60").arg(secid_1);
    }else{
       url  = QString("http://qt.gtimg.cn/q=%1").arg(secid_2);
    }

    m_manager.get(QNetworkRequest(QUrl(url)));
}

void StockPriceFetcher::onReplyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug()<<reply->error();
        qDebug() << "errorString:" << reply->errorString();
        qDebug() << "http status:"
                 << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "response:" << reply->readAll();
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    if (m_urlType == E_EAST_FU)
    {
        // 假设返回格式：
        // { "price": 12.34 }
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isObject())
            return;
        QJsonObject root = doc.object();
        QJsonObject dataObj = root.value("data").toObject();

        QString name = dataObj.value("f58").toString();
        double price = dataObj.value("f43").toDouble() / 100.0;
        double dma = dataObj.value("f71").toDouble() / 100.0; //日均
        double open = dataObj.value("f46").toDouble() / 100.0;
        double old = dataObj.value("f60").toDouble() / 100.0;
        double in = (price - old) / old * 100.0;

        emit jsonUpdated(JsonPkg{name,price,dma,open,in});
    }else{

        // 1. 获取 GBK 编解码器
        QTextCodec *codec = QTextCodec::codecForName("GBK");

        // 2. 将原始字节转换为 QString
        QString ret = codec->toUnicode(data);
        QStringList ls = ret.split("~");

        QString name = ls.at(1);
        double price = ls.at(3).toDouble();
        double dma = ls.at(7).toDouble() / ls.at(6).toDouble() * 100.0;
        double open = ls.at(3).toDouble() - ls.at(4).toDouble();
        double in = ls.at(5).toDouble();

        emit jsonUpdated(JsonPkg{name,price,dma,open,in});
    }







}

void StockPriceFetcher::onReplyFinishedName(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug()<<reply->error();
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    // 假设返回格式：
    // { "price": 12.34 }
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject())
        return;
    QJsonObject root = doc.object();
    QJsonArray arr = root.value("QuotationCodeTable").toObject().value("Data").toArray();
    QString ret;
    for (auto iter: arr)
    {
       ret += "代码: [" + iter.toObject().value("Code").toString() + "]";
       ret += "  类型: " + iter.toObject().value("SecurityTypeName").toString() + "\n";

    }

    emit jsonNameUpdated(ret);
}
