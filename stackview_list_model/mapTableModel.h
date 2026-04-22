#ifndef MAPTABLEMODEL_H
#define MAPTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QPointF>
#include <QVector>

class MapTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Roles { XValue = Qt::UserRole + 1, YValue };

    explicit MapTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override { return m_data.count(); }
    int columnCount(const QModelIndex &parent = QModelIndex()) const override { return 2; } // 第一列X，第二列Y

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid()) return QVariant();
        if (index.column() == 0) return m_data[index.row()].x();
        if (index.column() == 1) return m_data[index.row()].y();
        return QVariant();
    }

    /// 追加一个采样点；超过上限会丢弃最旧数据，避免长时间运行内存与绘图开销线性增长。
    void add(float value);

signals:

private:
    QVector<QPointF> m_data;

};

#endif // MAPTABLEMODEL_H
