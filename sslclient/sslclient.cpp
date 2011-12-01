#include <QByteArray>
#include <QList>
#include <QSslCertificate>
#include <QString>
#include "sslclient.h"

SslClient :: SslClient(QObject* parent)
  : QObject( parent )
{
  connect( &client, SIGNAL(encrypted()), this, SLOT(connectionEstablished()));
  connect( &client, SIGNAL(sslErrors(const QList<QSslError> &)), this, SLOT(errorOccured(const QList<QSslError> &)));
  
}


void SslClient :: start(QString hostName, quint16 port)
{
  client.connectToHostEncrypted(hostName, port);
}

void SslClient :: connectionEstablished()
{
  qDebug() << "SslClient :: connectionEstablished";
  QSslCertificate cert = client.peerCertificate();
  client.write("Hello, world\n", 14);
}

void SslClient :: errorOccured(const QList<QSslError> &error)
{
  qDebug() << "SslClient :: errorOccured";
  Q_UNUSED(error);
  client.ignoreSslErrors();
}

