#include <QtGui>
#include <QtQuick>
#include <filesystem>
#include <memory>
#include <qtgql/bases/bases.hpp>
#include <qtgql/gqloverhttp/gqloverhttp.hpp>

#include  "grapgql/__generated__/Qu.hpp"
#include "grapgql/__generated__/RemoveAnimalByName.hpp"
#include "grapgql/__generated__/schema.hpp"


namespace fs = std::filesystem;

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    // set up an environment
    auto env = std::shared_ptr<qtgql::bases::Environment>(
            new qtgql::bases::Environment("Zoo",

std::shared_ptr<qtgql::bases::NetworkLayerABC>
        (new qtgql::gqloverhttp::GraphQLOverHttp({"http://127.0.0.1:8000/graphql/"})))
    );
    // Export it
    qtgql::bases::Environment::set_gql_env(env);
    engine.addImportPath({"/home/ilays/CLionProjects/zooUI/UI/build/Debug/qml"});

    auto cont_mutation = Zoo::removeanimalbyname::RemoveAnimalByName::shared();
    cont_mutation->set_variables({"Lion"});
    //cont_mutation->fetch();
    engine.rootContext()->setContextProperty("deleteAnimal", cont_mutation.get());


    // Create an operation handler
    auto cont_query = Zoo::qu::Qu::shared();
    //cont_query->set_variables(Countries::continentquery::ContinentQueryVariables{.code="EU"});
    cont_query->fetch();
    engine.rootContext()->setContextProperty("query", cont_query.get());

    QUrl url((fs::path(__FILE__).parent_path() / "main.qml").c_str());
    engine.load(url);
    return QGuiApplication::exec();
}
