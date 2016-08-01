## This file is part of flcrum.
## Copyright (c) 2016 Jeremy Roberts.  See LICENSE for more information.
##----------------------------------------------------------------------------//

project(flcrum)
cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)
enable_testing()
include(CTest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)

if(NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR} CACHE STRING
      "Installation prefix; default is build directory."
      FORCE)
endif()

message("---------------------------------------------------------------------")
message("              SUMMARY OF CMAKE CONFIGURATION                         ")
message("---------------------------------------------------------------------")
message("++++ System:      ${CMAKE_SYSTEM} ${CMAKE_SYSTEM_PROCESSOR}")
message("++++ CXX:         ${CMAKE_CXX_COMPILER}")
message("++++ Build type:  ${CMAKE_BUILD_TYPE}")
message("++++ Install:     ${CMAKE_INSTALL_PREFIX}")


