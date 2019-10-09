#include <QObject>

class CustomBackend;
class SourcesBackend;
class TrendingBackend;

namespace ApplicationEnums {
enum class ApplicationPage;
}

class Dispatcher : public QObject {
    Q_OBJECT

    //TODO: At the start of the application fetch all the sources and populate the sources Model in all API's
    Q_PROPERTY(ApplicationEnums::ApplicationPage applicationPage READ applicationPage NOTIFY applicationPageChanged)
    Q_PROPERTY(QString currentPage READ currentPage NOTIFY currentPageChanged)

    Q_PROPERTY(TrendingBackend* trendingBackend READ trendingBackend CONSTANT)
    Q_PROPERTY(SourcesBackend* sourcesBackend READ sourcesBackend CONSTANT)
    Q_PROPERTY(CustomBackend* customBackend READ customBackend CONSTANT)

public:
    explicit Dispatcher(QObject* parent = nullptr);

    ApplicationEnums::ApplicationPage applicationPage() const;
    Q_INVOKABLE void setApplicationPage(ApplicationEnums::ApplicationPage applicationPage);

    QString currentPage() const;

    TrendingBackend* trendingBackend() const;
    SourcesBackend* sourcesBackend() const;
    CustomBackend* customBackend() const;

    Q_INVOKABLE void fetchSources();
    Q_INVOKABLE void fetchTrending();
    Q_INVOKABLE void fetchCustom();

signals:
    void applicationPageChanged();
    void currentPageChanged();

private:
    void setCurrentPage(const QString& currentPage);

private:
    TrendingBackend* m_trendingBackend{ nullptr };
    SourcesBackend* m_sourcesBackend{ nullptr };
    CustomBackend* m_customBackend{ nullptr };
    ApplicationEnums::ApplicationPage m_applicationPage;
    QString m_currentPage;
};
