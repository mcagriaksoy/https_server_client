# https_server_client

HTTPS server client solution written by modern c++.
This project contains an HTTPS server and client implemented in C++ using the httplib library.

# Usage

To establish the https connection, we need a ssl key. So we need to create SSL key pairs via Openssl first.

```
cd cert
openssl req -newkey rsa:2048 -new -nodes -x509 -days 3650 -keyout key.pem -out cert.pem
```

This project requires the httplib library with OpenSSL support. To build the project, run `make`.

## Files

- `https_server.cpp`: Contains the implementation of the HTTPS server.
- `https_client.cpp`: Contains the implementation of the HTTPS client.
- `https.h`: Header file for the HTTPS server and client.

## Functions

- `https_server(const std::string &ip_addr, const int port, const std::string &page_name, const std::string &str)`: Starts an HTTPS server at the specified IP address and port, serving the specified page with the specified content.
- `https_client(const std::string &ip_addr, const int port, std::string &output)`: Sends an HTTPS request to the specified server and port, and stores the response in `output`.

## Author

Mehmet Cagri Aksoy

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
