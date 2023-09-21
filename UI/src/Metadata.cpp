//
// Created by ilays on 9/21/23.
//

#include "Metadata.hpp"

Metadata::Metadata(QString domain, QString kingdom, QString pyhlum, QString _class, QString superfamily, QString family,
                   QObject *parent = nullptr): QObject(parent) {
    m_domain = domain;
    m_kingdom = kingdom;
    m_pyhlum = pyhlum;
    m_class = _class;
    m_superfamily = superfamily;
    m_family = family;
}

Metadata::Metadata(const QJsonObject &data) {
    m_domain = data["domain"].toString();
    m_kingdom = data["kingdom"].toString();
    m_pyhlum = data["pyhlum"].toString();
    m_class = data["Class"].toString();
    m_superfamily = data["superfamily"].toString();
    m_family = data["family"].toString();
}
