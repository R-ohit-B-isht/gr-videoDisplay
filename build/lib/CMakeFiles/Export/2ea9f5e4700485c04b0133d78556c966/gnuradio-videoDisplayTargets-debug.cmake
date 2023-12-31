#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gnuradio::gnuradio-videoDisplay" for configuration "Debug"
set_property(TARGET gnuradio::gnuradio-videoDisplay APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gnuradio::gnuradio-videoDisplay PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libgnuradio-videoDisplay.so.1.0.0.0"
  IMPORTED_SONAME_DEBUG "libgnuradio-videoDisplay.so.1.0.0"
  )

list(APPEND _cmake_import_check_targets gnuradio::gnuradio-videoDisplay )
list(APPEND _cmake_import_check_files_for_gnuradio::gnuradio-videoDisplay "${_IMPORT_PREFIX}/lib/libgnuradio-videoDisplay.so.1.0.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
