//
// Created by ilays on 9/21/23.
//
#pragma once
#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QtQml>

class Metadata: public QObject {
Q_OBJECT
    Q_PROPERTY(QString domain MEMBER m_domain NOTIFY domainChanged)
    Q_PROPERTY(QString kingdom MEMBER m_kingdom NOTIFY kingdomChanged)
    Q_PROPERTY(QString pyhlum MEMBER m_pyhlum NOTIFY pyhlumChanged)
    Q_PROPERTY(QString _class MEMBER m_class NOTIFY _classChanged)
    Q_PROPERTY(QString superfamily MEMBER m_superfamily NOTIFY superfamilyChanged)
    Q_PROPERTY(QString family MEMBER m_family NOTIFY familyChanged)

    signals:
    void domainChanged();
    void kingdomChanged();
    void pyhlumChanged();
    void _classChanged();
    void superfamilyChanged();
    void familyChanged();

public:
    Metadata (QString domain, QString kingdom, QString pyhlum, QString _class, QString superfamily,
              QString family, QObject *parent);
    explicit Metadata(const QJsonObject &data);


private:
    QString m_domain;
    QString m_kingdom;
    QString m_pyhlum;
    QString m_class;
    QString m_superfamily;
    QString m_family;
};