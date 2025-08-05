cmake_minimum_required(VERSION 3.10)
project(TestRTSPStreamer)

find_package(rtspshm REQUIRED)
find_package(Live555 REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(rtsp_test main.cpp)

target_link_libraries(rtsp_test
  PRIVATE
    rtspshm::rtspshm
    ${LIVE555_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
)

target_include_directories(rtsp_test PRIVATE ${LIVE555_INCLUDE_DIRS})


#add_executable(reader_main reader_main.cpp)
#target_link_libraries(reader_main PRIVATE rtspshm::rtspshm OpenSSL::SSL OpenSSL::Crypto)

#add_executable(writer_main writer_main.cpp)
#target_link_libraries(writer_main PRIVATE rtspshm::rtspshm OpenSSL::SSL OpenSSL::Crypto)
