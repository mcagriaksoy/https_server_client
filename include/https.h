// Description: HTTPS header file.
#ifndef HTTPS_H
#define HTTPS_H

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

enum server_error_code
{
    SERVER_SUCCESS = 0,
    SERVER_FAILURE = 1
};

enum client_error_code
{
    CLIENT_SUCCESS = 0,
    CLIENT_FAILURE = 1
};

server_error_code https_server(std::string &str);

client_error_code https_client(std::string &str);

#endif // HTTPS_H