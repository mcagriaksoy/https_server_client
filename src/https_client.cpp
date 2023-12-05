// Mehmet Cagri Aksoy

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../include/https.h"

client_error_code https_client(const std::string &ip_addr, const int port, std::string &output)
{
    if (ip_addr.empty() || port <= 0)
    {
        std::cout << "Invalid input!" << std::endl;
        return CLIENT_FAILURE;
    }

    if (ip_addr.size() > 15)
    {
        std::cout << "Invalid ip address!" << std::endl;
        return CLIENT_FAILURE;
    }

    // Call constructor with ip address and port number!
    httplib::SSLClient cli(ip_addr, port);
    try
    {
        // Use the CA bundle
        cli.set_ca_cert_path(GLOBAL_CERT_LOCATION);
        // Disable cert verification
        cli.enable_server_certificate_verification(true);
    }
    catch (const std::exception &e)
    {
        std::cout << "Throw: " << e.what() << std::endl;
        return CLIENT_FAILURE;
    }

    auto res = cli.Get("/");
    if (res)
    {
        std::cout << res->status << std::endl;
        std::cout << res->get_header_value("Content-Type") << std::endl;
        std::cout << res->body << std::endl;
    }
    else
    {
        auto result = cli.get_openssl_verify_result();
        if (result)
        {
            std::cout << "verify error: " << X509_verify_cert_error_string(result) << std::endl;
        }
    }

    return CLIENT_SUCCESS;
}