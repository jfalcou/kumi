##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================
cmake_minimum_required(VERSION 3.18)
project(kumi-fetch-test LANGUAGES CXX)
enable_testing()

message(STATUS "Testing FetchContent for commit ${kumi_git_head}")

# Enable FetchContent
include(FetchContent)

# Retrikumi KUMI from relative git directory
FetchContent_Declare(kumi
  GIT_REPOSITORY "${kumi_SOURCE_DIR}"
  GIT_TAG "${kumi_git_head}"
)

# make available
FetchContent_MakeAvailable(kumi)

add_executable(test_kumi ../main.cpp)
target_link_libraries(test_kumi PUBLIC kumi::kumi)
add_test(NAME test_kumi COMMAND test_kumi)
