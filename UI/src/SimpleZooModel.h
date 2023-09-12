#pragma once
#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QtQml>

class SimpleZooModel : public QAbstractListModel
{

Q_OBJECT

    struct Animal{
        QString name;
        int age;
        int weight;
        QString food;
    };

public:
    enum AnimalAttributes {
    age = Qt::UserRole,
    weight = Qt::UserRole + 1,
    food = Qt::UserRole + 2,
};
public: // QAbstractItemModel interface
    explicit SimpleZooModel(QObject *parent = nullptr);
~SimpleZooModel() override;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    //Q_INVOKABLE void insert(QString nameAnimal, QList<QString> *list);
    QHash<int, QByteArray> roleNames() const override;
//protected:
private:
    QHash<int ,QByteArray> m_map_data;
    QList<Animal> m_data;
    //QString convertToString(QMap<QList<QString>, QString> map) const;
};
