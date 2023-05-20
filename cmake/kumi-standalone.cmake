##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================

##==================================================================================================
## Standalone generation
##==================================================================================================
find_package(Python COMPONENTS Interpreter)

if(Python_FOUND)
  add_custom_command(OUTPUT tuple.hpp
    COMMAND "${Python_EXECUTABLE}"
            ${CMAKE_CURRENT_SOURCE_DIR}/src/embed.py
            ${CMAKE_CURRENT_SOURCE_DIR}/src/kumi/tuple.hpp
            -I src/
            -o ${CMAKE_CURRENT_SOURCE_DIR}/include/kumi/tuple.hpp
            --include-match kumi/*

    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    COMMENT "Generating standalone headers"
    VERBATIM
  )

  add_custom_target(kumi-standalone DEPENDS tuple.hpp)
  set(KUMI_FORCE_STANDALONE 1)
endif()
