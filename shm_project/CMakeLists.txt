cmake_minimum_required(VERSION 3.10)
project(SharedMemoryNALU C CXX)

# Thiết lập C chuẩn và C++ chuẩn
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Bao gồm thư mục header
include_directories(include)

# Tạo thư viện shm (object lib để dùng cả C & C++)
add_library(shm STATIC
    src/shared_mem.cpp
)

# Writer executable
add_executable(writer test/writer_main.cpp)
target_link_libraries(writer shm pthread)

# Reader executable
add_executable(reader test/reader_main.cpp)
target_link_libraries(reader shm pthread)

# Tùy chọn: thêm flags cảnh báo nghiêm ngặt
add_compile_options(-Wall -Wextra -Werror)
