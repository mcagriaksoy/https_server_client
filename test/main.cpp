

#include "../include/https.h"
#include <iostream>
#include <thread>

void server_thread(std::string &str)
{
    std::cout << "Server thread started" << std::endl;

    server_error_code retVal_server = https_server(str);
}

void client_thread(std::string &str)
{
    std::string str_tmp;
    std::cout << "Client thread started" << std::endl;

    client_error_code retVal_client = https_client(str_tmp);
    if (retVal_client == CLIENT_SUCCESS)
    {
        std::cout << "Client response: " << str_tmp << std::endl;
    }
    else
    {
        std::cout << "Error: " << retVal_client << std::endl;
        std::cout << "Client response: " << str_tmp << std::endl;
    }
}

int main()
{
    std::string str_server = "Hello World!";
    std::string str_client;

    std::thread serverThread(server_thread, std::ref(str_server));
    std::thread clientThread(client_thread, std::ref(str_client));

    serverThread.join();
    clientThread.join();

    return 0;
}