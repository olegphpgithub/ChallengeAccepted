#ifndef UNIVERSALMODEL_H
#define UNIVERSALMODEL_H

#include <QAbstractTableModel>

class UniversalModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit UniversalModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

signals:

};

#endif // UNIVERSALMODEL_H
