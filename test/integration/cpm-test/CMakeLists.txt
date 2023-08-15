##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.18)
project(kumi-cpm-test LANGUAGES CXX)
enable_testing()

message(STATUS "Testing CPM for branch ${GIT_BRANCH}")

# Setup CPM
include(cpm.cmake)

# Add dependencies
CPMAddPackage ( NAME kumi
                GIT_REPOSITORY "https://github.com/jfalcou/kumi.git"
                GIT_TAG "${GIT_BRANCH}"
                OPTIONS "KUMI_BUILD_TEST OFF"
              )

# Use kumi
add_executable(test_kumi ../main.cpp)
target_link_libraries(test_kumi PUBLIC kumi::kumi)
add_test(NAME test_kumi COMMAND test_kumi)
