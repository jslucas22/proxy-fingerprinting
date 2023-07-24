#ifndef PROXY_SERVER_H
#define PROXY_SERVER_H

#include <boost/asio.hpp>
#include "HttpHandler.h"

class ProxyServer
{
public:
    ProxyServer(boost::asio::io_context& io_context, int port);
    void start();

private:
    void acceptConnection();
    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif // PROXY_SERVER_H