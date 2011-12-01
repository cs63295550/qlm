#include <QObject>
#include <QSslSocket>
#include <QString>

class SslClient : public QObject
{
  Q_OBJECT

public:
  SslClient(QObject* parent = 0);
  void start(QString hostName, quint16 port);

public slots:
  void connectionEstablished();
  void errorOccured(const QList<QSslError> &error);

private:
  QSslSocket client;
};
