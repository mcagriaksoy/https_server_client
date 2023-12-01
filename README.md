# https_server_client

HTTPS server client solution written by modern c++

# Usage

To establish the https connection, we need a ssl key. So we need to create SSL key pairs via Openssl first.

```
cd cert
openssl req -newkey rsa:2048 -new -nodes -x509 -days 3650 -keyout key.pem -out cert.pem
```
