// TlsClient.cpp: определяет точку входа для приложения.
//

#include "TlsClient.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/Net/InvalidCertificateHandler.h>
#include <Poco/SharedPtr.h>
#include <Poco/Net/PrivateKeyPassphraseHandler.h>
#include <Poco/Net/X509Certificate.h>
#include <Poco/Net/SecureStreamSocket.h>
#include <Poco/Net/DialogSocket.h>
#include <Poco/StreamCopier.h>
#include <Poco/Exception.h>

using namespace std;
using namespace Poco::Net;
using namespace Poco;

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

    try {
        // Инициализация SSL
        initializeSSL();

        // Обработчик сертификатов (принимает любой)
        SharedPtr<InvalidCertificateHandler> pCertHandler =
            new AcceptCertificateHandler(false);

        // TLS-контекст с нашими файлами
        Context::Ptr context = new Context(
            Context::CLIENT_USE,
            clientKeyFile,
            clientCertFile,
            caCertFile,
            Context::VERIFY_RELAXED,
            9,
            true
        );

        // Установка глобального SSL менеджера
        SSLManager::instance().initializeClient(
            nullptr,      // можно позже добавить обработчик пароля
            pCertHandler,
            context
        );

        std::cout << "TLS-контекст успешно инициализирован\n";
    }
    catch (const Exception& ex) {
        std::cerr << "Ошибка TLS: " << ex.displayText() << std::endl;
        return 1;
    }

    return 0;
}

