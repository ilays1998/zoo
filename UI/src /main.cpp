//
// Created by ilay on 9/10/23.
//

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/hello/main.qml"_qs);
    engine.load(url);

    return app.exec();
}