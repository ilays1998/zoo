//
// Created by ilay on 9/13/23.
//

#include "Animal.h"

Animal::Animal( QString name, int age, int weight, QString food, QObject *parent = nullptr): QObject(parent) {
    m_name =name;
    m_weight = weight;
    m_food = food;
    m_age = age;
}


int Animal::getAge() const {
    return m_age;
}
int Animal::getWeight() const {
    return m_weight;
}
QString Animal::getFood() const {
    return m_food;
}

void Animal::setFood(const QString& f) {
    if (f != m_food) {
        m_food = f;
        emit foodChanged();
    }
}

void Animal::setAge(int a) {
    if (a != m_age) {
        m_age = a;
        emit ageChanged();
    }
}

void Animal::setWeight(int w) {
    if (w != m_weight) {
        m_weight = w;
        emit weightChanged();
    }
}