##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================
cmake_minimum_required(VERSION 3.18)
enable_testing()

##==================================================================================================
## Setup project
##==================================================================================================
project(kumi LANGUAGES CXX)

set(KUMI_MAJOR_VERSION 2)
set(KUMI_MINOR_VERSION 1)
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

## =================================================================================================
## Exporting target for external use
## =================================================================================================
include(kumi-install)

##==================================================================================================
## Options
##==================================================================================================
option( KUMI_BUILD_TEST          "Build tests for kumi" ON )
option( KUMI_BUILD_DOCUMENTATION "Build docs for kumi" OFF )
option( KUMI_BUILD_INTEGRATION   "Build integration tests for kumi" OFF )

##==================================================================================================
## Test target
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
  find_package(Doxygen QUIET)

  if (DOXYGEN_FOUND)
    message( STATUS "[kumi] Doxygen available")
  else (DOXYGEN_FOUND)
    message( STATUS "[kumi] Doxygen need to be installed to generate the doxygen documentation")
  endif (DOXYGEN_FOUND)

  if (DOXYGEN_FOUND)
    set(DOXYGEN_CONFIG ${PROJECT_SOURCE_DIR}/doc/Doxyfile)
    add_custom_target ( kumi-doxygen
      COMMAND KUMI_DOXYGEN_OUPUT=../docs ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIG}
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc
      COMMENT "[kumi] Generating API documentation with Doxygen"
      VERBATIM
    )

    add_custom_target (  kumi-doxygen-local
                        COMMAND KUMI_DOXYGEN_OUPUT=${PROJECT_BINARY_DIR}/docs ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIG}
                        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc
                        COMMENT "[kumi] Generating API documentation with Doxygen - Local version"
                        VERBATIM
                      )
  endif (DOXYGEN_FOUND)
endif()


##==================================================================================================
## Standalone generation
##==================================================================================================
add_custom_command(OUTPUT tuple.hpp
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/src/embed.py"
          ${CMAKE_CURRENT_SOURCE_DIR}/src/kumi/tuple.hpp
          -I src/
          -o ${CMAKE_CURRENT_SOURCE_DIR}/include/kumi/tuple.hpp
          --include-match kumi/*

  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  COMMENT "Generating standalone headers"
  VERBATIM
)

add_custom_target(kumi-standalone DEPENDS tuple.hpp)
