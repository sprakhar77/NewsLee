#pragma once

#include <QObject>

class CustomAPI : public QObject {
    Q_OBJECT
public:
    explicit CustomAPI(QObject* parent = nullptr);
};
