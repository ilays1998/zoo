#pragma once
#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QtQml>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "Animal.hpp"

inline const QByteArray HTTP_CONTENT_TYPE = "application/json";
inline const QByteArray HTTP_ACCEPT = "application/graphql-response+json";

class SimpleZooModel : public QAbstractListModel
{

    Q_OBJECT
    QML_ELEMENT
    //Q_PROPERTY(Animal* animal WRITE appendAnimal NOTIFY animalChanged)


signals:
    void animalChanged();


public: // QAbstractItemModel interface

    SimpleZooModel(QObject *parent = nullptr);


    enum RoleNames {
        animal = Qt::UserRole,
//        age = Qt::UserRole+2,
//        weight = Qt::UserRole+3,
//        food = Qt::UserRole+4
    };
~SimpleZooModel() override;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

//TODO: append integrative function, append another animal to the zoo, erase animal from the zoo
//Q_INVOKABLE request_data

//    Q_INVOKABLE void appendAnimal(Animal *a);
//    Q_INVOKABLE QString animals();
//protected:
    //TODO:add signals, possible bug if the data from the db didn't come before clicking on the zoo picture
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
private:
    QHash<int ,QByteArray> m_map_data;
    //TODO: memory leak possible
    std::vector<Animal*> m_data;
    //TODO: memory leak possible

    QNetworkAccessManager * m_manager;
    QNetworkRequest m_request;
    QByteArray m_doc;
    //QString convertToString(QMap<QList<QString>, QString> map) const;
};
