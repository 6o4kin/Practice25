cmake_minimum_required(VERSION 3.8)

project("TlsClient")

find_package(Poco REQUIRED COMPONENTS Util Net NetSSL Foundation Crypto)

# Добавляем исполняемый файл
add_executable(TlsClient 
    "TlsClient.cpp" 
    "TlsClient.h"
)

# Устанавливаем стандарт C++20
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем библиотеки POCO
target_link_libraries(TlsClient PRIVATE
    Poco::Util
    Poco::Net
    Poco::NetSSL
    Poco::Foundation
    Poco::Crypto
)