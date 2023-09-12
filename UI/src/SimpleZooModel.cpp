//
// Created by ilay on 9/11/23.
//

#include "SimpleZooModel.h"

SimpleZooModel::SimpleZooModel(QObject *parent)
        : QAbstractListModel(parent)
{
    m_data.append({"tiger", 20, 120, "beef"});
    m_data.append({"tiger", 20, 120, "beef"});
    m_data.append({"tiger", 20, 120, "beef"});
    m_data.append({"tiger", 20, 120, "beef"});
    m_data.append({"tiger", 20, 120, "beef"});

    m_map_data[age] = "age";
    m_map_data[weight] = "weight";
    m_map_data[food] = "food";
}


int SimpleZooModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    // return number of animals
    return m_data.size();
}
QVariant SimpleZooModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }
    const Animal& animal = m_data.at(row);
    switch(role) {
        case age:
            return animal.age;
        case weight:
            return animal.weight;
        case food:
            return animal.food;
    }


    return QVariant();

}
//QString SimpleZooModel::get(QString name, QString attribute) {
//    switch (condition) {
//
//    }
//    return m_map_data[name].animal_age.second;
//}
//
//QString SimpleZooModel::convertToString(QMap<animalAttribute, QString> map) const {
//    QString result;
//    result = "age: " + map[age] + "/n";
//    result = "weight: " + map[weight] + "/n";
//    result = "food: " + map[food] + "/n";
//    return result;
//}
//
//void SimpleZooModel::insert(QString nameAnimal, QList<QString> *list) {
//    animalDetails animalDetails;
//
//    QPair<animalAttribute, QString> animal_age;
//    animal_age.first = animalAttribute::age;
//    animal_age.second = list->at(0);
//
//    QPair<animalAttribute, QString> animal_weight;
//    animal_age.first = weight;
//    animal_age.second = list->at(1);
//
//    QPair<animalAttribute, QString> animal_food;
//    animal_age.first = food;
//    animal_age.second = list->at(2);
//
//    animalDetails.animal_age = animal_age;
//    animalDetails.animal_weight = animal_weight;
//    animalDetails.animal_food = animal_food;
//
//    m_map_data[nameAnimal] = animalDetails;
//    m_data.append(nameAnimal);
//}

QHash<int, QByteArray> SimpleZooModel::roleNames() const{
    return m_map_data;
}

SimpleZooModel::~SimpleZooModel() {

}
