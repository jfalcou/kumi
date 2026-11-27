##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================

##======================================================================================================================
## Take the dependencies from the environment, without CPM
##======================================================================================================================
option(KUMI_EXTERNAL_DEPENDENCIES "Take dependencies from the environment instead of fetching them" OFF)

##======================================================================================================================
## Retrieve a package declared below, from the environment or by CPM
##======================================================================================================================
macro(kumi_get_package name)
  if(KUMI_EXTERNAL_DEPENDENCIES)
    find_package(${name} CONFIG REQUIRED)
  else()
    CPMGetPackage(${name})
  endif()
endmacro()

if(KUMI_EXTERNAL_DEPENDENCIES)
  if(NOT COPACABANA_SOURCE_DIR)
    message(FATAL_ERROR "[KUMI] - KUMI_EXTERNAL_DEPENDENCIES needs COPACABANA_SOURCE_DIR")
  endif()
  return()
endif()

##======================================================================================================================
## CPM is vendored: the download bootstrap reports nothing on a failure and leaves an empty file.
##======================================================================================================================
include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

##======================================================================================================================
## Retrieve dependencies
##======================================================================================================================
CPMAddPackage(NAME COPACABANA GITHUB_REPOSITORY jfalcou/copacabana GIT_TAG e96014671dfb262482346ddcaa3a1a810b3eebaf)

CPMDeclarePackage(
  TTS
  NAME TTS
  GITHUB_REPOSITORY jfalcou/tts
  GIT_TAG 5b268b654b0af9aa46406710f23e5297a7658605
  SYSTEM YES
  OPTIONS "TTS_BUILD_TEST OFF" "TTS_BUILD_DOCUMENTATION OFF" "TTS_QUIET ON")
