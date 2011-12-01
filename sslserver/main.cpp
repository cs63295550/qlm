#include <QApplication>
#include "sslserver.h"

int main( int argc, char ** argv )
{
  QApplication app(argc, argv);
  SslServer server;
  server.listen( QHostAddress::Any, 8888);
  return app.exec();
}
