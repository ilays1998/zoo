#pragma once
#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QtQml>
#include "Animal.h"

class SimpleZooModel : public QAbstractListModel
{

    Q_OBJECT
    //Q_PROPERTY(Animal* animal WRITE appendAnimal NOTIFY animalChanged)


signals:
    void animalChanged();


public: // QAbstractItemModel interface
    enum RoleNames {
        animal = Qt::UserRole,
//        age = Qt::UserRole+2,
//        weight = Qt::UserRole+3,
//        food = Qt::UserRole+4
    };
    explicit SimpleZooModel(QObject *parent = nullptr);
~SimpleZooModel() override;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const override;
//    Q_INVOKABLE void appendAnimal(Animal *a);
//    Q_INVOKABLE QString animals();
//protected:
private:
    QHash<int ,QByteArray> m_map_data;
    std::vector<Animal*> m_data;
    //QString convertToString(QMap<QList<QString>, QString> map) const;
};
