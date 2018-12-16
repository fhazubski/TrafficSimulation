cmake_minimum_required(VERSION 3.9)
project(tslib VERSION 1.0.0 DESCRIPTION "Traffic Simulation Library")
include(GNUInstallDirs)
add_library(tslib SHARED source/test.cpp)
set_target_properties(tslib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/base.h)
#configure_file(tslib.pc.in tslib.pc @ONLY)
target_include_directories(tslib PRIVATE .)
#install(TARGETS tslib
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
#install(FILES ${CMAKE_BINARY_DIR}/tslib.pc
#    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
    