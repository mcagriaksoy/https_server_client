

#include "../include/https.h"
#include <iostream>
#include <thread>

void server_thread(std::string &ip_addr, int port, std::string &str)
{
    std::cout << "Server thread started" << std::endl;

    server_error_code retVal_server = https_server(ip_addr, port, str);
    if (retVal_server == SERVER_SUCCESS)
    {
        std::cout << "Server established!" << std::endl;
    }
    else
    {
        std::cout << "Server Down! " << std::endl;
    }
}

void client_thread(std::string &ip_addr, int port)
{
    std::cout << "Client thread started" << std::endl;
    std::string output;

    client_error_code retVal_client = https_client(ip_addr, port, output);
    if (retVal_client == CLIENT_SUCCESS)
    {
        std::cout << "Client response: " << output << std::endl;
    }
    else
    {
        std::cout << "Error: " << retVal_client << std::endl;
        std::cout << "Client response: " << output << std::endl;
    }
}

int main()
{
    std::string text = "Hello World!";
    std::string ip_addr = "127.0.0.1";
    int port = 8080;

    std::thread serverThread(server_thread, std::ref(ip_addr), port, std::ref(text));
    std::thread clientThread(client_thread, std::ref(ip_addr), port);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    serverThread.join();
    clientThread.join();

    return 0;
}