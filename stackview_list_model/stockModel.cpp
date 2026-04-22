#include "stockModel.h"

stockModel::stockModel(QObject *parent) : QAbstractListModel(parent)
{

}

void stockModel::setDataList(const QList<JsonPkg> &list)
{
    const int oldSize = m_data.size();
    const int newSize = list.size();
    const int common = qMin(oldSize, newSize);

    for (int i = 0; i < common; ++i) {
        m_data[i] = list.at(i);
    }

    if (common > 0) {
        emit dataChanged(index(0, 0), index(common - 1, 0));
    }

    if (newSize > oldSize) {
        beginInsertRows(QModelIndex(), oldSize, newSize - 1);
        for (int i = oldSize; i < newSize; ++i) {
            m_data.append(list.at(i));
        }
        endInsertRows();
    } else if (newSize < oldSize) {
        beginRemoveRows(QModelIndex(), newSize, oldSize - 1);
        while (m_data.size() > newSize) {
            m_data.removeLast();
        }
        endRemoveRows();
    }
}
