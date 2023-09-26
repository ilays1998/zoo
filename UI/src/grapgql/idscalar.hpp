#pragma once
#include <qtgql/customscalars/customscalars.hpp>


class url: public qtgql::customscalars::CustomScalarABC<QString, QString>{
public:
    const QString & GRAPHQL_NAME() override{
        static QString ret = "url";
        return ret;
    }
    void deserialize(const QJsonValue &raw_data) override{
        m_value = raw_data.toString();
    }
    QJsonValue serialize() const override{
        return { m_value};
    }
    const QString & to_qt() override{
        return m_value;
    }

};

