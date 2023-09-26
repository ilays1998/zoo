//
// Created by ilay on 9/11/23.
//
//
#include "SimpleZooModel.hpp"

SimpleZooModel::SimpleZooModel(QObject *parent) : QAbstractListModel(parent) {

    m_manager = new QNetworkAccessManager(this);

    foo();


}

void SimpleZooModel::deleteAnimal(QString name) {
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QJsonObject mutationObject;
    mutationObject["query"] = "mutation RemoveAnimalByName($name: String!) { removeAnimalByName(name: $name) { error data } }";
    mutationObject["variables"] = QJsonObject{
            {"name", name} // Replace 123 with the actual value for $pk
    };
    QByteArray doc = QJsonDocument(mutationObject).toJson();
    request.setUrl(QUrl(URL_ADDRESS));
    request.setRawHeader("Accept", HTTP_ACCEPT);
    request.setRawHeader("Content-Type", HTTP_CONTENT_TYPE);
    auto reply = manager->post(request,doc);

    auto it = m_data.begin();
    int index = 0;
    while(it != m_data.end()) {
        if (QString::compare((*it)->getName(), name) == 0) {
            this->beginRemoveRows(QModelIndex(), index, index);
            it = m_data.erase(it);
            this->endRemoveRows();
            index++;
        }
        else {
            it++;
            index++;
        }
    }

    QObject::connect(reply, &QNetworkReply::finished,
                     this, [=]() {
                qDebug() << "arrived here";
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QByteArray answer = reply->readAll();
                QJsonDocument qJsonDocument = QJsonDocument::fromJson(answer);
                auto temp = qJsonDocument["data"]["error"];
                qDebug() << temp.toArray();
                if (qJsonDocument.isNull()) {
                    qDebug() << reply->errorString();
                    return;
                }



                reply->deleteLater();
            }
    );
}

void SimpleZooModel::foo() {
    QJsonObject jsonObject;
    jsonObject = {
            {"query","query{\n  animals{\n    id\n     name\n     age\n     image\n    metadata{\n      domain\n"
                     "      kingdom\n      pyhlum\n      Class\n      superfamily\n      family\n    }\n  }\n}"}
    };
    m_doc = QJsonDocument(jsonObject).toJson();
    m_request.setUrl(QUrl(URL_ADDRESS));
    m_request.setRawHeader("Accept", HTTP_ACCEPT);
    m_request.setRawHeader("Content-Type", HTTP_CONTENT_TYPE);
    auto reply = m_manager->post(m_request, m_doc);

    m_map_data[animal] = "animal";

    connect(reply, &QNetworkReply::finished,
                     this, [=]() {
                qDebug() << "arrived here";
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

    QByteArray answer = reply->readAll();
    QJsonDocument qJsonDocument = QJsonDocument::fromJson(answer);
    auto temp = qJsonDocument["data"]["animals"];
    qDebug() << temp.toArray();
    if (qJsonDocument.isNull()) {
        qDebug() << reply->errorString();
        return;
    }

    for (const QJsonValue &jsonValue : temp.toArray()) {
        if (jsonValue.isObject()) {
            QJsonObject data = jsonValue.toObject();
            Animal* a = new Animal(data);
            beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
            m_data.push_back(a);
            endInsertRows();
            QModelIndex topLeft = createIndex(0, 0);
            QModelIndex bottomRight = createIndex(0, 1);
            //QObject::connect(a, SIGNAL(ageChanged()), this, SLOT(this->animalChanged()));
            //a->ageChanged();
        }
    }



    //picture from the web



    reply->deleteLater();
    }
    );
}



//SimpleZooModel::SimpleZooModel(QObject *parent)
//        : QAbstractListModel(parent)
//{

//    m_map_data[animal] = "animal";
////    m_map_data[age] = "age";
////    m_map_data[weight] = "weight";
////    m_map_data[food] = "food";
//}


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
//TODO: need to delete the allocate memory.
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