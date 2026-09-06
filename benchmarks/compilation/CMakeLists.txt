##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
## What the same workload costs to compile, written once with kumi and once with the standard library. Each source is
## compiled at three sizes, so the report shows a slope rather than a point. Nothing here is run.
##======================================================================================================================
set(BENCH_SIZES 4 16 64)

add_library(kumi_bench INTERFACE)
target_compile_features(kumi_bench INTERFACE cxx_std_20)
target_include_directories(kumi_bench INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

## The kumi side sees the library, the standard side must not: a header it does not include is a header it does not pay
## for, and that is the whole measurement.
add_library(kumi_bench_kumi INTERFACE)
target_link_libraries(kumi_bench_kumi INTERFACE kumi_bench)
target_include_directories(kumi_bench_kumi INTERFACE ${PROJECT_SOURCE_DIR}/include)

add_custom_target(kumi-bench COMMENT "[KUMI] - Building every compilation benchmark")

## One generated source per size, so that the cost report carries a line for each: three lines of the same file share
## a path, and the report would sum them into one.
foreach(side IN ITEMS kumi std)
  file(GLOB sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/${side} ${side}/*.cpp)

  foreach(source IN LISTS sources)
    cmake_path(GET source STEM name)

    foreach(size IN LISTS BENCH_SIZES)
      set(target bench.${side}.${name}.${size}.exe)
      set(generated ${CMAKE_CURRENT_BINARY_DIR}/${side}/${name}.${size}.cpp)

      file(WRITE ${generated} "#define BENCH_N ${size}\n#include \"${CMAKE_CURRENT_SOURCE_DIR}/${side}/${source}\"\n")

      add_executable(${target} ${generated})
      set_target_properties(${target} PROPERTIES EXCLUDE_FROM_ALL TRUE EXCLUDE_FROM_DEFAULT_BUILD TRUE
                                                 RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/benchmarks")

      if(side STREQUAL "kumi")
        target_link_libraries(${target} PRIVATE kumi_bench_kumi)
      else()
        target_link_libraries(${target} PRIVATE kumi_bench)
      endif()

      add_dependencies(kumi-bench ${target})
    endforeach()
  endforeach()
endforeach()
