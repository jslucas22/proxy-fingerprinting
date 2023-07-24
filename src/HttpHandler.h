#ifndef HTTP_HANDLER_H
#define HTTP_HANDLER_H

#include <string>
#include <boost/asio.hpp>

class HttpHandler
{
public:
    HttpHandler(boost::asio::ip::tcp::socket clientSocket);
    void handle();

private:
    void handleRequest();
    void handleResponse();

    boost::asio::ip::tcp::socket clientSocket;
    std::string requestData;
    std::string responseData;

    const std::string kOriginalResponseWebglVendor = "gl.getParameter(gl.VENDOR)";
    const std::string kOriginalResponsewebglRenderer = "gl.getParameter(gl.RENDERER)";
};

#endif // HTTP_HANDLER_H