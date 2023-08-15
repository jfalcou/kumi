##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.22)
project(kumi-fetch-test LANGUAGES CXX)
enable_testing()

message(STATUS "Testing FetchContent for branch ${GIT_BRANCH}")

# Enable FetchContent
include(FetchContent)

# Retrieve KUMI from relative git directory
FetchContent_Declare(kumi
  GIT_REPOSITORY "https://github.com/jfalcou/kumi.git"
  GIT_TAG ${GIT_BRANCH}
)

# make available
FetchContent_MakeAvailable(kumi)

add_executable(test_kumi ../main.cpp)
target_link_libraries(test_kumi PUBLIC kumi::kumi)
add_test(NAME test_kumi COMMAND test_kumi)
