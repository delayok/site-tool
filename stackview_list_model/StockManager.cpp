#include "StockManager.h"

StockManager::StockManager(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(900);

    connect(m_timer, &QTimer::timeout, this, &StockManager::onRequestUrl);
    connect(&m_mager, &QNetworkAccessManager::finished,this, &StockManager::onReplyFinished);
    connect(&m_managerName, &QNetworkAccessManager::finished,this, &StockManager::onReplyFinishedName);

    m_timer->start();

    m_model = new stockModel(this);
    m_curveMgr = new CurveManger(this);

    m_setting = new setting(this);
    for (auto code : m_setting->getCode())
    {
        setcurcode(code);
    }

}

StockManager::~StockManager()
{
    m_setting->saveCodels(m_codelist);
}

void StockManager::onRequestUrl()
{

    QUrl url;
    if (m_codelist.count()== 0)
        return;

    QString code_com;
    for(auto code : m_codelist)
    {
        QString secid_2,secid_1;
        if (code.startsWith("6")) {
            // sh
            secid_1 =  "1." + code;//.rightJustified(8, '0')
            secid_2 = "s_sh" + code;
        } else {
            // sz（000 / 002 / 300）
            secid_1 =  "0." + code;
            secid_2 = "s_sz" + code;
        }

        code_com += secid_2 + ",";
    }
    code_com.remove(code_com.lastIndexOf(","),1);
    url.setUrl( QString("http://qt.gtimg.cn/q=%1").arg(code_com));
    m_mager.get(QNetworkRequest(url));

}

void StockManager::onReplyFinished(QNetworkReply *reply)
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

    // 1. 获取 GBK 编解码器
    QTextCodec *codec = QTextCodec::codecForName("GBK");

    // 2. 将原始字节转换为 QString
    QString ret = codec->toUnicode(data);

    QStringList codels = ret.split(";");
    QList<stockModel::JsonPkg> jsonls;
    for (auto code : codels)
    {
        QStringList ls = code.split("~");
        if (ls.count()< 8)
            continue;

        QString codeid = ls.at(2);
        QString name = ls.at(1);
        double price = ls.at(3).toDouble();
        double dma = ls.at(6).toDouble() == 0.0 ? 0: ls.at(7).toDouble() / ls.at(6).toDouble() * 100;
        dma =  int(dma * 100) / 100.0;
        double open = ls.at(3).toDouble() - ls.at(4).toDouble();
        double in = ls.at(5).toDouble();

        jsonls.append(stockModel::JsonPkg{codeid,name,price,dma,open,in});

        m_curveMgr->addData(codeid,in);
        emit updateRealY(codeid,in);

    }
    m_model->setDataList(jsonls);

}

void StockManager::onReplyFinishedName(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug()<<reply->error();
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

#if 0// 东方
    // 假设返回格式：
    // { "price": 12.34 }
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject())
        return;
    QJsonObject root = doc.object();
    QJsonArray arr = root.value("QuotationCodeTable").toObject().value("Data").toArray();
    QString ret;
    QString defaultcode;
    for (auto iter: arr)
    {
       if (iter == arr.at(0))
       {
           defaultcode =  iter.toObject().value("Code").toString();
       }
       ret += "代码: [" + iter.toObject().value("Code").toString() + "]";
       ret += "  类型: " + iter.toObject().value("SecurityTypeName").toString() + "\n";

    }
    setcurcode(defaultcode);
#endif
    // 1. 获取 GBK 编解码器
    QTextCodec *codec = QTextCodec::codecForName("GBK");

    // 2. 将原始字节转换为 QString
    QString ret = codec->toUnicode(data);

    QStringList ls = ret.split("~");
    if (ls.count() < 2)
        return;

    QString ss = ls.at(1);
    setcurcode(ss);

}

void StockManager::onStart()
{
    m_timer->start();
}

