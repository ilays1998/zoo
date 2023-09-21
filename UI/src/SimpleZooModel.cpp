//
// Created by ilay on 9/11/23.
//
//
#include "SimpleZooModel.hpp"

SimpleZooModel::SimpleZooModel(QObject *parent) : QAbstractListModel(parent) {
    m_manager = new QNetworkAccessManager(this);

    QJsonObject jsonObject;
    jsonObject = {
            {"query","query{\n  animals{\n    id\n     name\n     age\n     image\n    metadata{\n      domain\n"
                     "      kingdom\n      pyhlum\n      Class\n      superfamily\n      family\n    }\n  }\n}"}
    };
    m_doc = QJsonDocument(jsonObject).toJson();
    m_request.setUrl(QUrl("http://127.0.0.1:8000/graphql/"));
    m_request.setRawHeader("Accept", HTTP_ACCEPT);
    m_request.setRawHeader("Content-Type", HTTP_CONTENT_TYPE);
    auto reply = m_manager->post(m_request,m_doc);

    m_map_data[animal] = "animal";

    QObject::connect(reply, &QNetworkReply::finished,
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
            m_data.push_back(new Animal(data));
        }
    }





//    //picture from the web
//    QObject::connect(m_manager, &QNetworkAccessManager::finished, this, SimpleZooModel::downloadFinished);
//    const QUrl url = QUrl("http://computer/a.jpg");
//    QNetworkRequest request(url);
//    nam->get(request);
//    reply->deleteLater();

    }
    );


}

//void SimpleZooModel::downloadFinished()
//{
//    QPixmap pm;
//    pm.loadFromData(reply->readAll());
//    ui->label->setPixmap(pm);
//}
//SimpleZooModel::SimpleZooModel(QObject *parent)
//        : QAbstractListModel(parent)
//{
//
//    m_data.push_back(new Animal{"tiger", "beef", 20,new Metadata("Eukaryota",
//    "Animalia",
//    "Chordata",
//    "Maammalia",
//    "Carnivora",
//    "Ursidea", nullptr), nullptr});
//    m_data.push_back(new Animal{"lion", "beef", 20,new Metadata("Eukaryota",
//                                                                "Animalia",
//                                                                "Chordata",
//                                                                "Maammalia",
//                                                                "Carnivora",
//                                                                "Ursidea", nullptr), nullptr});
//    m_data.push_back(new Animal{"elephant", "beef", 20,new Metadata("Eukaryota",
//                                                                    "Animalia",
//                                                                    "Chordata",
//                                                                    "Maammalia",
//                                                                    "Carnivora",
//                                                                    "Ursidea", nullptr), nullptr});
//    m_data.push_back(new Animal{"ant", "beef", 20,new Metadata("Eukaryota",
//                                                               "Animalia",
//                                                               "Chordata",
//                                                               "Maammalia",
//                                                               "Carnivora",
//                                                               "Ursidea", nullptr), nullptr});
//
//
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