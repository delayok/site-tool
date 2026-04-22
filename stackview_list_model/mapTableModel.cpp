#include "mapTableModel.h"

namespace {
// 与 RealTimeCurve.qml 中 ValueAxis.max 保持一致；可按机器性能调高/调低。
constexpr int kMaxCurvePoints = 6000;
}

MapTableModel::MapTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    m_data.clear();

}

void MapTableModel::add(float value)
{
    if (m_data.size() >= kMaxCurvePoints) {
//        beginResetModel();
//        const int trim = static_cast<int>(m_data.size()) - kMaxCurvePoints + 1;
//        m_data.erase(m_data.begin(), m_data.begin() + trim);
//        for (int i = 0; i < m_data.size(); ++i)
//            m_data[i].setX(i);
//        m_data.append(QPointF(m_data.size(), value));
//        endResetModel();
//        return;
        m_data.remove(0,10);
    }

    const int row = m_data.size();
    beginInsertRows(QModelIndex(), row, row);
    m_data.append(QPointF(row, value));
    endInsertRows();
}
