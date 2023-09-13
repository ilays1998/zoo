//
// Created by ilay on 9/11/23.
//
//
#include "SimpleZooModel.h"


SimpleZooModel::SimpleZooModel(QObject *parent)
        : QAbstractListModel(parent)
{

    m_data.push_back(new Animal{"tiger", 20, 120, "beef", nullptr});
    m_data.push_back(new Animal{"lion", 20, 120, "beef", nullptr});
    m_data.push_back(new Animal{"elephant", 20, 120, "beef", nullptr});
    m_data.push_back(new Animal{"ant", 20, 120, "beef", nullptr});


    m_map_data[animal] = "animal";
//    m_map_data[age] = "age";
//    m_map_data[weight] = "weight";
//    m_map_data[food] = "food";
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
    if(row < 0 || row >= m_data.size()) {
        return QVariant();
    }
    return QVariant::fromValue(static_cast<QObject*>( m_data.at(row)));

}
//QString SimpleZooModel::get(QString name, QString attribute) {
//    switch (condition) {
//
//    }
//    return m_map_data[name].animal_age.second;
//}



QHash<int, QByteArray> SimpleZooModel::roleNames() const{
    return m_map_data;
}

SimpleZooModel::~SimpleZooModel() {

}
//QString SimpleZooModel::getSnakeFood() const {
//    return m_data.at(3).food;
//}

//void SimpleZooModel::setSnakeFood(QString food)  {
//    Animal animal = m_data.at(3);
//    animal.food = food;
//    m_data.replace(3,animal);
//    emit snakeFoodChanged();
//}



//void SimpleZooModel::appendAnimal(Animal* a) {
//    m_data.push_front(a);
//}

//QString SimpleZooModel::animals() {
//    QString str = "animals: \n";
//    for (auto i : m_data) {
//        str += (i->getName()) + ", ";
//        str += std::to_string(i->getAge()) + ", ";
//        str += std::to_string(i->getWeight()) + ", ";
//        str += (i->getFood()) + "\n";
//
//    }
//    return str;
//}