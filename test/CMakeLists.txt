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
copa_glob_unit(QUIET PATTERN "doc/*.cpp"  INTERFACE kumi_docs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR})

##======================================================================================================================
## Unit tests
##======================================================================================================================
copa_glob_unit( QUIET
                PATTERN "unit/*.cpp" INTERFACE kumi_test
                RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
              )

##======================================================================================================================
## Device tests - they need a GPU at run time.
##======================================================================================================================
if(CMAKE_CUDA_COMPILER)
  copa_glob_unit( QUIET
                  PATTERN "cuda/tuple/*.cu" INTERFACE kumi_test
                  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
                  DESTINATION "cuda"
                )

  # A record test needs the identifiers of test.hpp, which nvcc refuses to parse
  if(CMAKE_CUDA_COMPILER_ID MATCHES "Clang")
    copa_glob_unit( QUIET
                    PATTERN "cuda/record/*.cu" INTERFACE kumi_test
                    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
                    DESTINATION "cuda"
                  )
  endif()
endif()
