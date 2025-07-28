##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
copa_setup_test_targets()
set(root "${CMAKE_SOURCE_DIR}/test")

##======================================================================================================================
## Documentation tests
##======================================================================================================================
copa_glob_unit(QUIET PATTERN "doc/*.cpp"  INTERFACE kumi_docs OPT_RELATIVE ${CMAKE_CURRENT_SOURCE_DIR})

##======================================================================================================================
## Unit tests
##======================================================================================================================
if(KUMI_BUILD_STANDALONE_TEST)
  copa_glob_unit( QUIET
                  PATTERN "unit/*.cpp" INTERFACE kumi_test_standalone
                  OPT_RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
                )
else()
  copa_glob_unit( QUIET
                  PATTERN "unit/*.cpp" INTERFACE kumi_test
                  OPT_RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
                )
endif()