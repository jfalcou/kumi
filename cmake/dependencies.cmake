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
##
## This file runs before the project can declare an option, copa_add_option arriving with copacabana, so a package
## wanted only under an option is declared here and fetched after the options, in CMakeLists.txt.
##======================================================================================================================
CPMAddPackage(NAME COPACABANA GITHUB_REPOSITORY jfalcou/copacabana GIT_TAG v8)

CPMDeclarePackage ( TTS   NAME TTS   GITHUB_REPOSITORY jfalcou/tts
                    GIT_TAG main
                    OPTIONS "TTS_BUILD_TEST OFF"
                            "TTS_BUILD_DOCUMENTATION OFF"
                            "TTS_QUIET ON"
                  )
