#include <QObject>

class Trending : public QObject {
    Q_OBJECT
public:
    explicit Trending(QObject* parent = nullptr);
};
