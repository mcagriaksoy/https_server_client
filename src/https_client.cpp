// Mehmet Cagri Aksoy

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../include/https.h"

client_error_code https_client(std::string &str)
{
    // HTTPS
    httplib::Client cli("https://127.0.0.1:8080");

    // Use your CA bundle
    cli.set_ca_cert_path("/home/mcagriaksoy/https_server_client/cert/cert.pem");

    // Disable cert verification
    cli.enable_server_certificate_verification(false);

    try
    {
        auto res = cli.Get("/hi");
        if (res->status != 200)
        {
            std::cout << "HTTP(s) Error Code: " << res->status << std::endl;
            return CLIENT_FAILURE;
        }
        std::cout << "HTTP(s) /hi Response: " << res->body << std::endl;

        res = cli.Get("/mainPage");
        std::cout << "HTTP(s) /mainPage Response: " << res->body << std::endl;
        str = res->body;

        res = cli.Post("/post", "text", "text/plain");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return CLIENT_FAILURE;
    }
    return CLIENT_SUCCESS;
}