// Mehmet Cagri Aksoy

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../include/https.h"

server_error_code https_server(std::string &str)
{

    httplib::Server svr;
    // HTTPS
    // httplib::SSLServer svr()
    std::string str_tmp;
    str_tmp = str;

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res)
            { res.set_content("Welcome!", "text/plain"); });

    svr.Get("/hi", [&](const httplib::Request &, httplib::Response &res)
            { res.set_content(str_tmp, "text/plain"); });

    svr.Get("/mainPage", [&](const httplib::Request &req, httplib::Response &res)
            { res.set_content(str_tmp, "text/plain"); });

    svr.Get("/body-header-param", [&](const httplib::Request &req, httplib::Response &res)
            {
    if (req.has_header("Content-Length")) {
      auto val = req.get_header_value("Content-Length");
    }
    if (req.has_param("key")) {
      auto val = req.get_param_value("key");
    }
    res.set_content(req.body, "text/plain"); });

    svr.Get("/stop", [&](const httplib::Request &req, httplib::Response &res)
            { svr.stop(); });

    svr.listen("127.0.0.1", 8080);

    return SERVER_SUCCESS;
}
