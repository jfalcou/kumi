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
CPMAddPackage(NAME COPACABANA GITHUB_REPOSITORY jfalcou/copacabana GIT_TAG d055131cbcc563e502321991b590d6682c6a8b3c)

CPMDeclarePackage(
  TTS
  NAME TTS
  GITHUB_REPOSITORY jfalcou/tts
  GIT_TAG e6b227c61634e4ec56b3b7ffd4a224a84f3f5c14
  SYSTEM YES
  OPTIONS "TTS_BUILD_TEST OFF" "TTS_BUILD_DOCUMENTATION OFF" "TTS_QUIET ON")
