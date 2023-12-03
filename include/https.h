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

// Somehow the httplib library does not work with relative paths.
// TODO fix this!
#define GLOBAL_CERT_LOCATION ("/home/mcagriaksoy/https_server_client/cert/ca.crt")
#define GLOBAL_KEY_LOCATION ("/home/mcagriaksoy/https_server_client/cert/ca.key")

/**
 * @brief Starts an HTTPS server at a specified IP address and port.
 *
 * This function creates an HTTPS server and starts it at the server
 * specified by `ip_addr` and `port`. The server will serve a single page with the content specified by `str`.
 *
 * @param ip_addr The IP address where the server will be started.
 * @param port The port number where the server will listen for incoming connections.
 * @param str The content that will be served on the server's main page.
 *
 * @return SERVER_SUCCESS if the server was started successfully, SERVER_FAILURE otherwise.
 */
server_error_code https_server(const std::string &ip_addr, const int port, const std::string &str);

/**
 * @brief Sends an HTTPS request to a specified server and port.
 *
 * This function creates an HTTPS client and sends a request to the server
 * specified by `ip_addr` and `port`. The request body is specified by `str`.
 *
 * @param ip_addr The IP address of the server to send the request to.
 * @param port The port number on the server to send the request to.
 * @param output Output param. The response from the server.
 *
 * @return CLIENT_SUCCESS if the request was sent successfully, CLIENT_FAILURE otherwise.
 */
client_error_code https_client(const std::string &ip_addr, const int port, std::string &output);

#endif // HTTPS_H