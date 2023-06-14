find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_VIDEODISPLAY gnuradio-videoDisplay)

FIND_PATH(
    GR_VIDEODISPLAY_INCLUDE_DIRS
    NAMES gnuradio/videoDisplay/api.h
    HINTS $ENV{VIDEODISPLAY_DIR}/include
        ${PC_VIDEODISPLAY_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_VIDEODISPLAY_LIBRARIES
    NAMES gnuradio-videoDisplay
    HINTS $ENV{VIDEODISPLAY_DIR}/lib
        ${PC_VIDEODISPLAY_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-videoDisplayTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_VIDEODISPLAY DEFAULT_MSG GR_VIDEODISPLAY_LIBRARIES GR_VIDEODISPLAY_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_VIDEODISPLAY_LIBRARIES GR_VIDEODISPLAY_INCLUDE_DIRS)
