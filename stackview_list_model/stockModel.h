#ifndef STOCKMODEL_H
#define STOCKMODEL_H

#include <QObject>
#include <QAbstractListModel>

class stockModel : public QAbstractListModel
{
    Q_OBJECT
public:

    struct JsonPkg{
        QString code;
        QString name;
        double price;
        double mhmov;//分时均线值
        double open;
        double increase;
    };

    enum Roles{
        NameRole = Qt::UserRole + 1,
        PriceRole,
        mhmovRole,
        openRole,
        increaseRole,
        codeRole
    };

    QHash<int, QByteArray> roleNames() const override {
           return {
               {NameRole, "name"},
               {PriceRole, "price"},
               {mhmovRole, "mhmov"},
               {openRole, "open"},
               {increaseRole, "increase"},
               {codeRole, "code"},
           };
       }

    explicit stockModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        Q_UNUSED(parent)
        return m_data.count();
    } ;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{
        if (index.row() < 0 || index.row() >= m_data.count())
            return QVariant();

        JsonPkg  j = m_data.at(index.row());
        switch (role) {
        case NameRole: return j.name;
        case PriceRole: return j.price;
        case mhmovRole: return j.mhmov;
        case openRole: return j.open;
        case increaseRole: return j.increase;
        case codeRole: return j.code;
        }
        return {};

    } ;

    void setDataList(const QList<JsonPkg> &list) {
        beginResetModel();
        m_data = list;
        endResetModel();
    }


signals:

private:
    QList<JsonPkg> m_data;

};

#endif // STOCKMODEL_H
