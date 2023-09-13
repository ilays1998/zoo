//
// Created by ilay on 9/13/23.
//

#pragma once

#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QtQml>


class Animal: public QObject{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name NOTIFY nameChanged)
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(int weight READ getWeight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(QString food READ getFood WRITE setFood NOTIFY foodChanged)

    signals:
            void foodChanged();
    void nameChanged();
    void weightChanged();
    void ageChanged();
public:
    Animal ( QString name, int age, int weight, QString food, QObject *parent);
    int getAge() const;
    int getWeight() const;
    QString getFood() const;
    void setFood(const QString& f);
    void setAge(int a);
    void setWeight(int w);
private:
    QString m_name;
    int m_age;
    int m_weight;
    QString m_food;
};


