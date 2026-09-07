##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
## What the same workload costs to compile, written once with kumi and once with the standard library. Each source is
## compiled at three sizes, so the report shows a slope rather than a point. Nothing here is run.
##======================================================================================================================
## From 4 to 64 by 4: the slope is what the comparison is about, and a single point says nothing. A cache variable,
## because a time trace writes a megabyte per unit and wants a handful of sizes, not sixteen.
set(KUMI_BENCH_SIZES "" CACHE STRING "Tuple sizes the compilation benchmark is run at, empty for 4 to 64 by 4")
set(BENCH_SIZES ${KUMI_BENCH_SIZES})
if(NOT BENCH_SIZES)
  foreach(size RANGE 4 64 4)
    list(APPEND BENCH_SIZES ${size})
  endforeach()
endif()

## Each point is compiled more than once. CPU time moves by about a fifth between two runs of the same translation
## unit, so a single figure says nothing about the one next to it; the reading takes the median of the runs.
set(KUMI_BENCH_REPEATS 3 CACHE STRING "How many times each point of the compilation benchmark is compiled")
set(BENCH_REPEATS ${KUMI_BENCH_REPEATS})

## Two shapes of the same workload: every element of a type of its own, and every element of the same type, which is
## the shape kumi has a representation for.
set(BENCH_SHAPES hetero homo)

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

    foreach(shape IN LISTS BENCH_SHAPES)
      foreach(size IN LISTS BENCH_SIZES)
        math(EXPR last_repeat "${BENCH_REPEATS} - 1")

        foreach(repeat RANGE ${last_repeat})
          set(target bench.${side}.${shape}.${name}.${size}.${repeat}.exe)
          set(generated ${CMAKE_CURRENT_BINARY_DIR}/${side}/${shape}/${name}.${size}.${repeat}.cpp)

          set(shape_define "")
          if(shape STREQUAL "homo")
            set(shape_define "#define BENCH_HOMOGENEOUS\n")
          endif()

          file(WRITE ${generated}
               "#define BENCH_N ${size}\n#define BENCH_REPEAT ${repeat}\n${shape_define}#include \"${CMAKE_CURRENT_SOURCE_DIR}/${side}/${source}\"\n")

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
  endforeach()
endforeach()
