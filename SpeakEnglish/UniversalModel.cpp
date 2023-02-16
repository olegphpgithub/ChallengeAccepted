#include "UniversalModel.h"

#include "MainCore.h"

UniversalModel::UniversalModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int UniversalModel::rowCount(const QModelIndex & /*parent*/) const
{
   return MainCore::table.count();
}

int UniversalModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant UniversalModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
        {
            return MainCore::table[index.row()].en;
        }
        else
        {
            return MainCore::table[index.row()].ru;
        }
        return QString("Row%1, Column%2")
                    .arg(index.row() + 1)
                    .arg(index.column() +1);
    }
    return QVariant();
}
