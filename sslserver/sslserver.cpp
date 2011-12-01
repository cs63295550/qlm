#include <QtCore>
#include <QtNetwork>
#include "sslserver.h"

const char *key =
  "-----BEGIN RSA PRIVATE KEY-----\n"
  " [insert your own] \n"
  "-----END RSA PRIVATE KEY-----\n";

const char *cert =
  " -----BEGIN CERTIFICATE-----\n"
  " [insert your own] \n"
  "-----END CERTIFICATE-----\n";

  
  
SslServer :: SslServer(QObject *parent)
  : QTcpServer(parent)
{
  server.setLocalCertificate( QSslCertificate(cert));
  server.setPrivateKey(QSslKey(key, QSsl::Rsa));
  connect( &server, SIGNAL(encrypted()), this, SLOT(readyWrite()));
}

void SslServer :: incomingConnection( int descriptor )
{
  server.setSocketDescriptor( descriptor );
  server.startServerEncryption();
  
}

void SslServer :: readyWrite()
{
  qDebug() << "SslServer :: readyWrite";
}
