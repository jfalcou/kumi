##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.22)
project(kumi LANGUAGES CXX)

##======================================================================================================================
option( KUMI_BUILD_TEST             "Build tests using Kumi headers"            ON  )
option( KUMI_BUILD_STANDALONE_TEST  "Build tests using Kumi standalone header"  OFF )
option( KUMI_BUILD_DOCUMENTATION    "Build Doxygen for Kumi"                    OFF )

##======================================================================================================================
include(${PROJECT_SOURCE_DIR}/cmake/dependencies.cmake)

if(KUMI_BUILD_TEST)
  include(${PROJECT_SOURCE_DIR}/cmake/compiler.cmake)
endif()

##======================================================================================================================
## Project setup via copacabana
##======================================================================================================================
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake ${COPACABANA_SOURCE_DIR}/copacabana/cmake)
include(${COPACABANA_SOURCE_DIR}/copacabana/cmake/copacabana.cmake)
copa_project_version(MAJOR 3 MINOR 1 PATCH 0)

##======================================================================================================================
## Summary Display
##======================================================================================================================
if(NOT KUMI_QUIET)
  if(KUMI_BUILD_STANDALONE_TEST)
    unset(KUMI_BUILD_TEST)
  endif()

  if(CMAKE_BUILD_TYPE)
    message(STATUS "[${PROJECT_NAME}] - Building in ${CMAKE_BUILD_TYPE} mode")
  endif()

  message(STATUS "[${PROJECT_NAME}] - Unit tests              : ${KUMI_BUILD_TEST} (via KUMI_BUILD_TEST)")
  message(STATUS "[${PROJECT_NAME}] - Unit tests (standalone) : ${KUMI_BUILD_STANDALONE_TEST} (via KUMI_BUILD_STANDALONE_TEST)")
  message(STATUS "[${PROJECT_NAME}] - Doxygen                 : ${KUMI_BUILD_DOCUMENTATION} (via KUMI_BUILD_DOCUMENTATION)")
  set(QUIET_OPTION "")
else()
  set(QUIET_OPTION "QUIET")
endif()

##======================================================================================================================
## Install Process setup
##======================================================================================================================
copa_setup_install( LIBRARY kumi
                    FEATURES cxx_std_20
                    DOC     ${PROJECT_SOURCE_DIR}/LICENSE.md
                    INCLUDE ${PROJECT_SOURCE_DIR}/include/kumi
                  )

##======================================================================================================================
## Setup doxygen
##======================================================================================================================
if(KUMI_BUILD_DOCUMENTATION)
  copa_setup_doxygen(${QUIET_OPTION} TARGET kumi-doxygen DESTINATION "${PROJECT_BINARY_DIR}/doc")
endif()

##======================================================================================================================
## Standalone generation
##======================================================================================================================
copa_setup_standalone ( QUIET
                        FILE kumi.hpp SOURCE include ROOT kumi TARGET kumi-standalone
                        OUTPUT "${PROJECT_BINARY_DIR}"
                      )

##======================================================================================================================
## Tests setup
##======================================================================================================================
if(KUMI_BUILD_TEST)
  enable_testing()
  add_custom_target(kumi-unit)
  add_subdirectory(test)
endif()
