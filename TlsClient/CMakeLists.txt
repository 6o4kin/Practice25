# CMakeList.txt: проект CMake для TlsClient; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TlsClient "TlsClient.cpp" "TlsClient.h")

target_link_libraries(TlsClient PRIVATE
    Poco::Foundation
    Poco::Net
    Poco::NetSSL
    Poco::Crypto
    Poco::Util
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TlsClient PROPERTY CXX_STANDARD 17)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
