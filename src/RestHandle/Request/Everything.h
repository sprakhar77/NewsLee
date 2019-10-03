#include <QObject>

class Everything : public QObject {
    Q_OBJECT
public:
    explicit Everything(QObject* parent = nullptr);
};
