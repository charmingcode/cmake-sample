cmake_minimum_required(VERSION 2.8)

add_library(hello SHARED hello.cc)

# For CMAKE_INSTALL_<dir> variables.
include(GNUInstallDirs)


# Headers: hello 
install(FILES
  hello.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hello)


install(TARGETS hello 
  EXPORT hello_export_set
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


install(EXPORT hello_export_set
  FILE testHelloTargets.cmake  
  DESTINATION ${CMAKE_INSTALL_DATADIR}/hello/cmake)


# Exported cmake file for the library.
#
# This is the main cmake entry point and should be included directly.
include(CMakePackageConfigHelpers)
configure_package_config_file(helloConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/helloConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/hello/cmake
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/helloConfig.cmake
  DESTINATION ${CMAKE_INSTALL_DATADIR}/hello/cmake
  RENAME testHelloConfig.cmake)
