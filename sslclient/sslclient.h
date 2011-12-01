#ifndef SSLCLIENT_H_DEF
#define SSLCLIENT_H_DEF

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
}; // class SslClient

#endif // SSLCLIENT_H_DEF
