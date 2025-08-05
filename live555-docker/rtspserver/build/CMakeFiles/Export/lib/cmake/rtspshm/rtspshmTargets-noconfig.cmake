#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rtspshm::rtspshm" for configuration ""
set_property(TARGET rtspshm::rtspshm APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(rtspshm::rtspshm PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librtspshm.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS rtspshm::rtspshm )
list(APPEND _IMPORT_CHECK_FILES_FOR_rtspshm::rtspshm "${_IMPORT_PREFIX}/lib/librtspshm.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
