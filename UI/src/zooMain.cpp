//
// Created by ilay on 9/11/23.
//

#include <QtGui>
#include <QtQml>
#include <QObject>
#include "SimpleZooModel.hpp"
#include "Animal.hpp"
#include <QAbstractItemModel>
#include <filesystem>
#include <QListView>

namespace fs = std::filesystem;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
//    SimpleZooModel* v = new SimpleZooModel();
    // register the type DataEntryModel
    // under the url "org.example" in version 1.0
    // under the name "DataEntryModel"

    //using the simple model
    SimpleZooModel zoo_model;
    QQmlApplicationEngine engine;
    auto qml_main = fs::path(__FILE__).parent_path() / "zooImage.qml";
    const QUrl url(QString::fromStdString(qml_main.string()));


    engine.rootContext()->setContextProperty("zooModel", &zoo_model);
    engine.load(QUrl(QString::fromStdString(qml_main.string())));
    return app.exec();
}