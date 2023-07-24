#include "ProxyServer.h"

int main()
{
    ProxyServer server(8080);
    server.start();
    return 0;
}