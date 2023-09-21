//
// Created by ilay on 9/13/23.
//

#include "Animal.hpp"

Animal::Animal( QString name,QString image, int age, Metadata* metadata, QObject *parent = nullptr): QObject(parent) {
    m_name = name;
    m_image = image;
    m_age = age;
    m_metadata = metadata;
}


int Animal::getAge() const {
    return m_age;
}

void Animal::setAge(int a) {
    if (a != m_age) {
        m_age = a;
        emit ageChanged();
    }
}

Animal::Animal(const QJsonObject &data) {
    m_name = data["name"].toString();
    m_age = data["age"].toInt();
    m_image = data["image"].toString();
    //const auto &jsonValue = data["metadata"].toObject();
    QJsonObject temp = data["metadata"].toObject();
    m_metadata = static_cast<Metadata*>(new Metadata(temp));
}

//int Animal::getWeight() const {
//    return m_weight;
//}
//QString Animal::getFood() const {
//    return m_food;
//}
//
//void Animal::setFood(const QString& f) {
//    if (f != m_food) {
//        m_food = f;
//        emit foodChanged();
//    }
//}
//
//void Animal::setWeight(int w) {
//    if (w != m_weight) {
//        m_weight = w;
//        emit weightChanged();
//    }
//}


