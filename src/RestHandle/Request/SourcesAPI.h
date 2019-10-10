#pragma once

#include <src/Model/CheckableModel/CheckableModelFactory.h>

#include <QObject>

class SourcesAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(CheckableModel* country READ country CONSTANT)
    Q_PROPERTY(CheckableModel* category READ category CONSTANT)
    Q_PROPERTY(CheckableModel* language READ language CONSTANT)

public:
    explicit SourcesAPI(QObject* parent = nullptr);

    QUrl prepareRequest();

    CheckableModel* country() const;
    CheckableModel* category() const;
    CheckableModel* language() const;

private:
    CheckableModel* m_country{ nullptr };
    CheckableModel* m_category{ nullptr };
    CheckableModel* m_language{ nullptr };
};
