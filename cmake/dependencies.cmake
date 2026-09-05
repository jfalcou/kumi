##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================

##======================================================================================================================
## CPM is vendored: the download bootstrap reports nothing on a failure and leaves an empty file.
##======================================================================================================================
include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

##======================================================================================================================
## Retrieve dependencies
##======================================================================================================================
CPMAddPackage(NAME COPACABANA GITHUB_REPOSITORY jfalcou/copacabana GIT_TAG v7)

# This file runs before the option is declared, so a cold configure sees it undefined and would
# skip TTS, leaving tts::tts dangling. A warm cache hides it.
if(NOT DEFINED KUMI_BUILD_TEST OR KUMI_BUILD_TEST)
  CPMAddPackage ( NAME TTS   GITHUB_REPOSITORY jfalcou/tts
                  GIT_TAG main
                  OPTIONS "TTS_BUILD_TEST OFF"
                          "TTS_BUILD_DOCUMENTATION OFF"
                          "TTS_QUIET ON"
                )
endif()
