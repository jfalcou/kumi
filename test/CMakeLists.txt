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
                  PATTERN "device/*.cu" INTERFACE kumi_test
                  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
                  DESTINATION "cuda"
                )
elseif(CMAKE_HIP_COMPILER)
  # hipcc is clang-based, so the whole device suite - tuple and record - compiles from the same
  # sources as the CUDA set. The .cu extension is forced to the HIP language, which CMake does not
  # treat as HIP on an AMD target otherwise. Only one back-end runs per configure: a card is from
  # one vendor, and sharing sources would make identical targets collide when both languages are on.
  file(GLOB_RECURSE HIP_DEVICE_TESTS CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "device/*.cu")
  set_source_files_properties(${HIP_DEVICE_TESTS} PROPERTIES LANGUAGE HIP)

  copa_make_unit( QUIET
                  INTERFACE kumi_test
                  DESTINATION "hip"
                  FILES ${HIP_DEVICE_TESTS}
                  ROOT "device"
                )
endif()
