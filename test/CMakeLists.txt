##==================================================================================================
##  KUMI - One File Wonders
##  Copyright : KUMI Contributors & Maintainers
##  SPDX-License-Identifier: MIT
##==================================================================================================

##==================================================================================================
## Compiler options
##==================================================================================================
add_library(kumi_test INTERFACE)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options( kumi_test INTERFACE /W3 /EHsc /std:c++latest)
else()
  target_compile_options( kumi_test INTERFACE -std=c++20 -Werror -Wall -Wextra)
endif()

target_include_directories( kumi_test INTERFACE
                            ${PROJECT_SOURCE_DIR}/test
                            ${PROJECT_SOURCE_DIR}/include
                          )

##==================================================================================================
## Make test
##==================================================================================================
function(generate_test root file)
  string(REPLACE ".cpp" ".exe" base ${file})
  string(REPLACE "/"    "." base ${base})
  string(REPLACE "\\"   "." base ${base})
  set(test "${root}.${base}")

  add_executable( ${test}  "${file}")
  target_link_libraries(${test} PUBLIC kumi_test)

  set_property( TARGET ${test}
                PROPERTY RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/unit"
              )

  if (CMAKE_CROSSCOMPILING_CMD)
    add_test( NAME ${test}
              WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/unit"
              COMMAND ${CMAKE_CROSSCOMPILING_CMD} $<TARGET_FILE:${test}> --no-color --pass
            )
  else()
    add_test( NAME ${test}
              WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/unit"
              COMMAND $<TARGET_FILE:${test}> --no-color --pass
            )
  endif()

  set_target_properties ( ${test} PROPERTIES
                          EXCLUDE_FROM_DEFAULT_BUILD TRUE
                          EXCLUDE_FROM_ALL TRUE
                          ${MAKE_UNIT_TARGET_PROPERTIES}
                        )

  target_include_directories( ${test}
                              PRIVATE
                              ${tts_SOURCE_DIR}/include
                              ${PROJECT_SOURCE_DIR}/test
                              ${PROJECT_SOURCE_DIR}/include
                            )

  add_dependencies(unit ${test})
endfunction()

add_custom_target(unit)

##==================================================================================================
## Actual tests
##==================================================================================================
generate_test("kumi"  "access.cpp"          )
generate_test("kumi"  "adapt.cpp"           )
generate_test("kumi"  "aggregate_ctor.cpp"  )
generate_test("kumi"  "apply.cpp"           )
generate_test("kumi"  "cat.cpp"             )
generate_test("kumi"  "convert.cpp"         )
generate_test("kumi"  "extract.cpp"         )
generate_test("kumi"  "flatten.cpp"         )
generate_test("kumi"  "fold.cpp"            )
generate_test("kumi"  "for_each.cpp"        )
generate_test("kumi"  "forward_as_tuple.cpp")
generate_test("kumi"  "make_tuple.cpp"      )
generate_test("kumi"  "map.cpp"             )
generate_test("kumi"  "reorder.cpp"         )
generate_test("kumi"  "split.cpp"           )
generate_test("kumi"  "tie.cpp"             )
generate_test("kumi"  "transpose.cpp"       )
generate_test("kumi"  "zip.cpp"             )
