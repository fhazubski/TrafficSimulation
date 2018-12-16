cmake_minimum_required(VERSION 3.9)
project(tslib VERSION 1.0.0 DESCRIPTION "Traffic Simulation Library")
include(GNUInstallDirs)
include(GenerateExportHeader)
add_library(tslib SHARED source/test.cpp)
generate_export_header(tslib)
set_target_properties(tslib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/api.h)
#configure_file(tslib.pc.in tslib.pc @ONLY)
set(LIBRARY_INSTALL_DIR ${PROJECT_SOURCE_DIR}/build/lib_install)
set(INCLUDE_INSTALL_DIR ${PROJECT_SOURCE_DIR}/build/include_install)
target_include_directories(tslib PRIVATE .)
install(TARGETS tslib DESTINATION ${LIBRARY_INSTALL_DIR})
install(FILES
 include/api.h
 source/base.h
 source/metrics.h
 source/types.h
 ${PROJECT_BINARY_DIR}/tslib_export.h DESTINATION ${INCLUDE_INSTALL_DIR}
)
