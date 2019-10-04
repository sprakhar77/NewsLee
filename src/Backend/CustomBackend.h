#include <QObject>

class CustomBackend : public QObject {
    Q_OBJECT
public:
    explicit CustomBackend(QObject* parent = nullptr);

signals:

public slots:
};
