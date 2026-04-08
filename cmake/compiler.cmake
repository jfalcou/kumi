##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================

##======================================================================================================================
## Common compiler options
##======================================================================================================================
add_library(kumi_opts INTERFACE)

target_compile_features ( kumi_opts INTERFACE cxx_std_20 )

if(CMAKE_CUDA_COMPILER_ID MATCHES "NVIDIA")
  target_compile_features( kumi_opts INTERFACE cuda_std_20 )
  target_compile_options( kumi_opts INTERFACE $<$<COMPILE_LANGUAGE:CUDA>:--Werror all-warnings -Xcompiler -Wno-deprecated-literal-operator> )
  # The literal warning is set at the moment when using nvcc13.2.5 with clang20
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "NVHPC")
  target_compile_options( kumi_opts INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-Werror -Wall -Wshadow -Wextra -Wunused-variable --diag_suppress implicit_return_from_non_void_function,set_but_not_used > )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if(CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    target_compile_options( kumi_opts INTERFACE  $<$<COMPILE_LANGUAGE:CXX>:/W3 /WX /EHsc> )
  else()
    target_compile_options( kumi_opts INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-Wshadow -Werror -Wall -Wextra -Wunused-variable -Wdocumentation -Wextra-semi> )
  endif()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  target_compile_options( kumi_opts INTERFACE $<$<COMPILE_LANGUAGE:CXX>:/W3 /WX /EHsc /Zc:preprocessor> )
else()
  target_compile_options( kumi_opts INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-Wshadow -Werror -Wall -Wextra -Wunused-variable -Wextra-semi> )
endif()

##======================================================================================================================
## Compiler options for Doc Tests
##======================================================================================================================
add_library(kumi_docs INTERFACE)

target_link_libraries(kumi_docs INTERFACE kumi_opts)
target_include_directories( kumi_docs INTERFACE
                            ${PROJECT_SOURCE_DIR}/test
                            ${PROJECT_SOURCE_DIR}/include
                          )

##======================================================================================================================
## Compiler options for Unit Tests of include/
##======================================================================================================================
add_library(kumi_test INTERFACE)

target_link_libraries(kumi_test INTERFACE kumi_opts tts::tts)
target_include_directories( kumi_test INTERFACE
                            ${PROJECT_SOURCE_DIR}/test
                            ${PROJECT_SOURCE_DIR}/include
                          )
