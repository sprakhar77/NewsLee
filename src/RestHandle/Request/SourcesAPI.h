#pragma once

#include <QObject>

class SourcesAPI : public QObject {
    Q_OBJECT
    // Add country, category, language models

public:
    explicit SourcesAPI(QObject* parent = nullptr);

    QUrl prepareRequest();
};
