# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)
# Устанавливаем путь к OpenSSL
set(OPENSSL_ROOT_DIR "C:/OpenSSL-Win64-Full")
# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Подключаем OpenSSL
find_package(OpenSSL REQUIRED)

project ("TlsClient")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Poco_DIR "C:/Users/Ant/Documents/libs/poco-main/cmake-build/Poco")
find_package(Poco REQUIRED COMPONENTS Foundation Net NetSSL Crypto Util)

# Включите подпроекты.
add_subdirectory ("TlsClient")
