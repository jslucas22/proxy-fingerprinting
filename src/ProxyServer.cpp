#include "ProxyServer.h"

ProxyServer::ProxyServer(boost::asio::io_context &io_context, int port)
    : acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

void ProxyServer::start()
{
    acceptConnection();
}

void ProxyServer::acceptConnection()
{
    acceptor_.async_accept(
        [this](boost::system::error_code ec, boost::asio::ip::tcp::socket clientSocket)
        {
            if (!ec)
            {
                std::make_shared<HttpHandler>(std::move(clientSocket))->handle();
            }

            acceptConnection();
        });
}