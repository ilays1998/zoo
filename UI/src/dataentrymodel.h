//
// Created by ilay on 9/11/23.
//

#ifndef HELLOWORLD_DATAENTRYMODEL_H
#define HELLOWORLD_DATAENTRYMODEL_H

#include <QtCore>
#include <QtGui>

class DataEntryModel : public QAbstractListModel
{
Q_OBJECT
public:
    explicit DataEntryModel(QObject *parent = 0);
    ~DataEntryModel();

public: // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
private:
    QList<QString> m_data;
};

#endif //HELLOWORLD_DATAENTRYMODEL_H
