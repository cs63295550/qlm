#include <QApplication>
#include "sslclient.h"

int main( int argc, char ** argv )
{
  QApplication app(argc, argv);
  SslClient client;
  client.start("127.0.0.1", 8888);
  return app.exec();
}
