// Mehmet Cagri Aksoy

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../include/https.h"

server_error_code https_server(const std::string &ip_addr, const int port, const std::string &str)
{
        if (ip_addr.empty() || port <= 0)
        {
                std::cout << "Invalid input!" << std::endl;
                return SERVER_FAILURE;
        }

        if (ip_addr.size() > 15)
        {
                std::cout << "Invalid ip address!" << std::endl;
                return SERVER_FAILURE;
        }

        // HTTPS
        httplib::SSLServer svr(GLOBAL_CERT_LOCATION, GLOBAL_KEY_LOCATION);
        try
        {
                std::string str_tmp = str;

                svr.Get("/", [](const httplib::Request &req, httplib::Response &res)
                        { res.set_content("Alive!", "text/plain"); });

                svr.Get("/hi", [&](const httplib::Request &, httplib::Response &res)
                        { res.set_content(str_tmp, "text/plain"); });

                svr.Get("/mainPage", [&](const httplib::Request &req, httplib::Response &res)
                        { res.set_content(str_tmp, "text/plain"); });

                svr.Get("/stop", [&](const httplib::Request &req, httplib::Response &res)
                        { svr.stop(); });

                svr.listen(ip_addr, port);
        }
        catch (const std::exception &e)
        {
                std::cout << e.what() << std::endl;
                return SERVER_FAILURE;
        }
        return SERVER_SUCCESS;
}
