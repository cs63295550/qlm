#ifndef SSLSERVER_H_DEF
#define SSLSERVER_H_DEF

#include <QObject>
#include <QSslSocket>
#include <QString>
#include <QTcpServer>

class SslServer : public QTcpServer
{
  Q_OBJECT

public:
  SslServer(QObject *parent = 0);

protected:
  virtual void incomingConnection( int descriptor );

protected slots:
  void readyWrite();
  
private:
  QSslSocket server;
}; // class SslServer

#endif // SSLSERVER_H_DEF
