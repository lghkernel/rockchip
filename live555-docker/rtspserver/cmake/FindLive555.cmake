# FindLive555.cmake

find_path(LIVE555_INCLUDE_DIR
    NAMES liveMedia.hh
    PATHS /usr/local/include /usr/include
    PATH_SUFFIXES liveMedia
)

find_library(LIVEMEDIA_LIBRARY liveMedia)
find_library(GROUPSOCK_LIBRARY groupsock)
find_library(USAGEENV_LIBRARY UsageEnvironment)
find_library(BASICUSAGEENV_LIBRARY BasicUsageEnvironment)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Live555 DEFAULT_MSG
    LIVE555_INCLUDE_DIR
    LIVEMEDIA_LIBRARY
    GROUPSOCK_LIBRARY
    USAGEENV_LIBRARY
    BASICUSAGEENV_LIBRARY
)

if(Live555_FOUND)
    set(LIVE555_INCLUDE_DIRS
        ${LIVE555_INCLUDE_DIR}
        /usr/local/include/groupsock
        /usr/local/include/UsageEnvironment
        /usr/local/include/BasicUsageEnvironment
    )
    set(LIVE555_LIBRARIES
        ${LIVEMEDIA_LIBRARY}
        ${GROUPSOCK_LIBRARY}
        ${USAGEENV_LIBRARY}
        ${BASICUSAGEENV_LIBRARY}
    )
endif()
