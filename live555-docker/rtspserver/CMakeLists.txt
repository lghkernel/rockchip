cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(rtspshm LANGUAGES CXX)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src RTSPSHM_SOURCES)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(Live555 REQUIRED)

set(RTSP_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RTSP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(rtspshm STATIC
    ${RTSPSHM_SOURCES}
)

target_include_directories(rtspshm
    PUBLIC
        $<BUILD_INTERFACE:${RTSP_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include/rtspshm>
        ${LIVE555_INCLUDE_DIRS}
)

target_link_libraries(rtspshm
    PUBLIC
        ${LIVE555_LIBRARIES}
        pthread
)

# Thêm phía dưới cùng của file rtsp/CMakeLists.txt
set(RTSPSHM_PROJECT_NAME rtspshm)
set(RTSPSHM_NAMESPACE rtspshm::)
set(RTSPSHM_TARGET_NAME rtspshm)
set(RTSPSHM_VERSION 1.0.0)
set(RTSPSHM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# === Install Library ===
install(TARGETS ${RTSPSHM_TARGET_NAME}
    EXPORT ${RTSPSHM_PROJECT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# === Install Headers ===
install(DIRECTORY ${RTSPSHM_INCLUDE_DIR}/
    DESTINATION include/${RTSPSHM_TARGET_NAME}
    FILES_MATCHING PATTERN "*.hh"
)

# === Export Targets ===
install(EXPORT ${RTSPSHM_PROJECT_NAME}Targets
    FILE ${RTSPSHM_PROJECT_NAME}Targets.cmake
    NAMESPACE ${RTSPSHM_NAMESPACE}
    DESTINATION lib/cmake/${RTSPSHM_PROJECT_NAME}
)

# === Generate & Install Config Files ===
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${RTSPSHM_PROJECT_NAME}ConfigVersion.cmake
    VERSION ${RTSPSHM_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/${RTSPSHM_PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${RTSPSHM_PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/${RTSPSHM_PROJECT_NAME}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${RTSPSHM_PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${RTSPSHM_PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${RTSPSHM_PROJECT_NAME}
)
