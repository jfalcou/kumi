##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Contributors & Maintainers
##  SPDX-License-Identifier: MIT
##==================================================================================================
cmake_minimum_required(VERSION 3.2)

##==================================================================================================
## Setup project
##==================================================================================================
project(kumi LANGUAGES CXX)
set(PROJECT_VERSION 0.1.0)

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

## =================================================================================================
## Exporting target for external use
## =================================================================================================
add_library(kumi_lib INTERFACE)
target_include_directories(kumi_lib INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
target_compile_options( kumi_lib INTERFACE -Wno-gnu-string-literal-operator-template)
endif()

target_compile_features(kumi_lib INTERFACE cxx_std_20)
add_library(kumi::kumi ALIAS kumi_lib)

##==================================================================================================
## Options
##==================================================================================================
option( KUMI_BUILD_TEST  "Build tests for kumi" ON )

##==================================================================================================
## Test target
##==================================================================================================
if( KUMI_BUILD_TEST )
  include(CTest)
  add_subdirectory(${PROJECT_SOURCE_DIR}/test/)
endif()
