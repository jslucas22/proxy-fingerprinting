#include "HttpHandler.h"

HttpHandler::HttpHandler(boost::asio::ip::tcp::socket clientSocket) : clientSocket(std::move(clientSocket)){};

void HttpHandler::handle()
{
    handleRequest();
    handleResponse();
}

void HttpHandler::handleRequest()
{
    boost::asio::read_until(clientSocket, boost::asio::dynamic_buffer(requestData), "\r\n\r\n");
}

void HttpHandler::handleResponse()
{
    size_t hostStart = requestData.find("Host: ");

    if (hostStart == std::string::npos)
    {
        return;
    }
    
    hostStart += 6;
    size_t hostEnd = requestData.find("\r\n", hostStart);
    
    if (hostEnd == std::string::npos)
    {
        return;
    }

    std::string host = requestData.substr(hostStart, hostEnd - hostStart);
    int port = 80;

    boost::asio::ip::tcp::socket serverSocket(clientSocket.get_executor().context());
    boost::asio::ip::tcp::resolver resolver(clientSocket.get_executor().context());
    auto endpoints = resolver.resolve(host, std::to_string(port));

    boost::asio::connect(serverSocket, endpoints);

    boost::asio::write(serverSocket, boost::asio::buffer(requestData));

    boost::asio::read_until(serverSocket, boost::asio::dynamic_buffer(responseData), "\r\n\r\n");

    size_t contentTypePos = responseData.find("Content-Type: ");
    bool isJavascript = false;

    if (contentTypePos != std::string::npos)
    {
        size_t endOfLinePos = responseData.find("\r\n", contentTypePos);

        std::string contentTypeValue = responseData.substr(contentTypePos + 13, endOfLinePos - (contentTypePos + 13));

        if (contentTypeValue == "application/javascript" ||
            contentTypeValue == "text/javascript" ||
            contentTypeValue == "application/x-javascript")
        {
            isJavascript = true;
        }
    }

    if (isJavascript)
    {
        size_t posVendor = responseData.find(kOriginalResponseWebglVendor);
        if (posVendor != std::string::npos)
        {
            responseData.replace(posVendor, kOriginalResponseWebglVendor.length(), "\"NOVIDE(O)...\"");
        }

        size_t posRenderer = responseData.find(kOriginalResponsewebglRenderer);
        if (posRenderer != std::string::npos)
        {
            responseData.replace(posRenderer, kOriginalResponsewebglRenderer.length(), "\"GT 1030 RODA ATE...\"");
        }
    }

    boost::asio::write(clientSocket, boost::asio::buffer(responseData));
}