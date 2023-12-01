// Mehmet Cagri Aksoy

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../include/https.h"

server_error_code https_server(std::string &str)
{
        // HTTPS
        httplib::SSLServer svr(
            "/home/mcagriaksoy/https_server_client/cert/cert.pem",
            "/home/mcagriaksoy/https_server_client/cert/key.pem");
        try
        {
                std::string str_tmp;
                str_tmp = str;

                svr.Get("/", [](const httplib::Request &req, httplib::Response &res)
                        { res.set_content("Welcome!", "text/plain"); });

                svr.Get("/hi", [&](const httplib::Request &, httplib::Response &res)
                        { res.set_content(str_tmp, "text/plain"); });

                svr.Get("/mainPage", [&](const httplib::Request &req, httplib::Response &res)
                        { res.set_content(str_tmp, "text/plain"); });

                svr.Get("/stop", [&](const httplib::Request &req, httplib::Response &res)
                        { svr.stop(); });

                svr.listen("127.0.0.1", 8080);
        }
        catch (const std::exception &e)
        {
                std::cout << e.what() << std::endl;
                return SERVER_FAILURE;
        }
        return SERVER_SUCCESS;
}
