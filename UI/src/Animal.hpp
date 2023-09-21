//
// Created by ilay on 9/13/23.
//

#pragma once

#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QtQml>
#include <QString>
#include "Metadata.hpp"


class Animal: public QObject{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name NOTIFY nameChanged)
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString image MEMBER m_image NOTIFY imageChanged)
    Q_PROPERTY(QObject* metadata MEMBER m_metadata NOTIFY metadatChanged)

    //Q_PROPERTY(int weight READ getWeight WRITE setWeight NOTIFY weightChanged)
    //Q_PROPERTY(QString food READ getFood WRITE setFood NOTIFY foodChanged)

    signals:
    //void weightChanged();
    //void foodChanged();
    void nameChanged();
    void ageChanged();
    void imageChanged();
    void metadatChanged();

public:
    explicit Animal(const QJsonObject & data);
    explicit Animal ( QString name, QString image, int age, Metadata* metadata, QObject *parent);
    int getAge() const;
    void setAge(int a);

//    int getWeight() const;
//    QString getFood() const;
//    void setFood(const QString& f);
//    void setWeight(int w);
    QString m_image;
private:
    QString m_name;
    int m_age;

    //TODO: memory leak possible
    QObject* m_metadata;

//    int m_weight;
//    QString m_food;
};


