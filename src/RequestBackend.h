#include <src/RestHandle/Everything.h>
#include <src/RestHandle/Sources.h>
#include <src/RestHandle/Trending.h>

class RequestBackend : public QObject {
    Q_OBJECT

    Q_PROPERTY(Everything* everything READ everything CONSTANT)
    Q_PROPERTY(Sources* sources READ sources CONSTANT)
    Q_PROPERTY(Trending* trending READ trending CONSTANT)

public:
    explicit RequestBackend(QObject* parent = nullptr);

    Everything* everything() const;
    Sources* sources() const;
    Trending* trending() const;

public slots:
    void onSourcesChanged();
    void onTrendingNewsChanged();

private:
    Everything* m_everything{ nullptr };
    Sources* m_sources{ nullptr };
    Trending* m_trending{ nullptr };
};
