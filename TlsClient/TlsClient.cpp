// TlsClient.cpp: определяет точку входа для приложения.
//

#include "TlsClient.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: TlsClient <client_key.pem> <client_cert.pem> <ca_cert.pem>\n";
        return 1;
    }

    std::string clientKeyFile = argv[1];
    std::string clientCertFile = argv[2];
    std::string caCertFile = argv[3];

    std::cout << "Key: " << clientKeyFile << std::endl;
    std::cout << "Cert: " << clientCertFile << std::endl;
    std::cout << "CA: " << caCertFile << std::endl;

    return 0;
}

