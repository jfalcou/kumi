##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================
cmake_minimum_required(VERSION 3.2)
enable_testing()

##==================================================================================================
## Setup project
##==================================================================================================
project(kumi LANGUAGES CXX)

set(KUMI_MAJOR_VERSION 3)
set(KUMI_MINOR_VERSION 0)
set(KUMI_PATCH_VERSION 0)
set(KUMI_VERSION ${KUMI_MAJOR_VERSION}.${KUMI_MINOR_VERSION}.${KUMI_PATCH_VERSION})

set(PROJECT_VERSION   ${KUMI_VERSION})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake )

##==================================================================================================
## No in-source build
##==================================================================================================
if (${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
  message(FATAL_ERROR "[kumi]: In-source build is not recommend")
endif()

## =================================================================================================
## Install target
## =================================================================================================
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/kumi TYPE INCLUDE)
include(kumi-install)

##==================================================================================================
## Options
##==================================================================================================
option( KUMI_BUILD_TEST          "Build tests for kumi" ON )
option( KUMI_BUILD_DOCUMENTATION "Build docs for kumi" OFF )
option( KUMI_BUILD_INTEGRATION   "Build integration tests for kumi" OFF )

##==================================================================================================
## Test targets
##==================================================================================================
if( KUMI_BUILD_TEST )
  include(CTest)
  add_subdirectory(${PROJECT_SOURCE_DIR}/test/)
endif()

if( KUMI_BUILD_INTEGRATION )
  include(CTest)
  add_subdirectory(${PROJECT_SOURCE_DIR}/test/integration)
endif()

##==================================================================================================
## Add Doxygen building target
##==================================================================================================
if( KUMI_BUILD_DOCUMENTATION )
  include(cmake/kumi-doxygen.cmake)
endif()

##==================================================================================================
## Standalone generation
##==================================================================================================
include(cmake/kumi-standalone.cmake)
