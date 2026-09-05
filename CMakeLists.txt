##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.28)
project(KUMI LANGUAGES CXX)

if(DEFINED CMAKE_CUDA_COMPILER)
  enable_language(CUDA)
endif()

##======================================================================================================================

##======================================================================================================================
include(${PROJECT_SOURCE_DIR}/cmake/dependencies.cmake)


##======================================================================================================================
## Project setup via copacabana
##======================================================================================================================
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake ${COPACABANA_SOURCE_DIR}/copacabana/cmake)
include(${COPACABANA_SOURCE_DIR}/copacabana/cmake/copacabana.cmake)

copa_add_option(KUMI_BUILD_TEST "Build tests using Kumi headers" ON LABEL "Unit tests")
copa_add_option(KUMI_BUILD_DOCUMENTATION "Build Doxygen for Kumi" OFF LABEL "Doxygen")
copa_add_option(KUMI_ENABLE_SANITIZERS "Build tests with AddressSanitizer + UndefinedBehaviorSanitizer" OFF LABEL "Sanitizers")
copa_add_option(KUMI_ENABLE_COVERAGE "Build tests with code coverage instrumentation" OFF LABEL "Coverage")
copa_add_option(KUMI_COMPILE_COST "Measure what every test unit costs to compile" OFF)

if(KUMI_BUILD_TEST)
  include(${PROJECT_SOURCE_DIR}/cmake/compiler.cmake)
endif()
copa_project_version(MAJOR 4 MINOR 0 PATCH 0 REPOSITORY https://github.com/jfalcou/kumi)

##======================================================================================================================
## Summary Display
##======================================================================================================================
copa_show_options()

if(NOT KUMI_QUIET)
  set(QUIET_OPTION "")
else()
  set(QUIET_OPTION "QUIET")
endif()

##======================================================================================================================
## Pre-commit hooks setup targets
##======================================================================================================================
copa_setup_precommit_hooks(${QUIET_OPTION})

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
  copa_setup_doxygen(${QUIET_OPTION}
                     TARGET kumi-doxygen
                     DESTINATION "${PROJECT_BINARY_DIR}/doc"
                     GODBOLT_LIBRARIES kumi
                     GODBOLT_COMPILER clang1600
                     GODBOLT_OPTIONS "-O3 -std=c++20 -DNDEBUG"
                     COLOR_HUE 293
                     COLOR_SATURATION 40
                     COLOR_LIGHTNESS 50)
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
  if(KUMI_ENABLE_SANITIZERS)
    copa_setup_sanitizers(kumi_opts ENABLE_ASAN ENABLE_UBSAN)
  endif()

  enable_testing()
  add_custom_target(kumi-unit)
  add_subdirectory(test)

  # After the test targets exist, so the coverage targets can depend on them
  if(KUMI_ENABLE_COVERAGE)
    copa_setup_coverage(kumi_opts)
  endif()

  # clang only: -fproc-stat-report is its flag. After the test targets, as the measurement rebuilds them.
  if(KUMI_COMPILE_COST)
    copa_setup_compile_cost(kumi_opts)
  endif()
endif()
