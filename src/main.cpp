#include "ProxyServer.h"
#include <boost/asio.hpp>

int main()
{
    boost::asio::io_context io_context;
    ProxyServer server(io_context, 8080);
    server.start();
    
    io_context.run();    
    return 0;
}
