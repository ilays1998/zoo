//
// Created by ilay on 9/10/23.
//

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    auto qml_main = fs::path(__FILE__).parent_path() / "zooImage.qml";
    const QUrl url(QString::fromStdString(qml_main.string()));
    engine.load(url);

    return app.exec();
    ;
}