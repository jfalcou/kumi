##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================

##======================================================================================================================
## Compiler options for Doc Tests
##======================================================================================================================
add_library(kumi_docs INTERFACE)

target_compile_features ( kumi_docs INTERFACE  cxx_std_20 )

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if(CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    target_compile_options( kumi_docs INTERFACE /W3 /EHsc )
  else()
    target_compile_options( kumi_docs INTERFACE -Wshadow -Werror -Wall -Wextra -Wunused-variable -Wdocumentation)
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options( kumi_docs INTERFACE /W3 /EHsc /Zc:preprocessor)
else()
  target_compile_options( kumi_docs INTERFACE -Wshadow -Werror -Wall -Wextra -Wunused-variable)
endif()

target_include_directories( kumi_docs INTERFACE
                            ${PROJECT_SOURCE_DIR}/test
                            ${PROJECT_SOURCE_DIR}/include
                          )

##======================================================================================================================
## Compiler options for Unit Tests
##======================================================================================================================
add_library(kumi_test INTERFACE)

target_link_libraries(kumi_test INTERFACE kumi_docs tts::tts)
