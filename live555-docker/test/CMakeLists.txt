cmake_minimum_required(VERSION 3.10)
project(TestRTSPStreamer)

# Tìm RTSPSHM (đã cài)
find_package(rtspshm REQUIRED)

# Tìm OpenSSL (để resolve undefined SSL_* symbol)
find_package(OpenSSL REQUIRED)

add_executable(rtsp_test main.cpp)
target_link_libraries(rtsp_test PRIVATE rtspshm::rtspshm OpenSSL::SSL OpenSSL::Crypto)

add_executable(reader_main reader_main.cpp)
target_link_libraries(reader_main PRIVATE rtspshm::rtspshm OpenSSL::SSL OpenSSL::Crypto)

add_executable(writer_main writer_main.cpp)
target_link_libraries(writer_main PRIVATE rtspshm::rtspshm OpenSSL::SSL OpenSSL::Crypto)
