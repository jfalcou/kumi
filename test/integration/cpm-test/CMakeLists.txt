##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================
cmake_minimum_required(VERSION 3.18)
project(kumi-cpm-test LANGUAGES CXX)
enable_testing()

message(STATUS "Testing CPM for commit ${kumi_git_head}")

# Setup CPM
include(cpm.cmake)

# Add dependencies
CPMAddPackage ( NAME kumi
                GIT_REPOSITORY "${kumi_SOURCE_DIR}"
                GIT_TAG "${kumi_git_head}"
                OPTIONS "KUMI_BUILD_INTEGRATION=OFF"
                        "KUMI_BUILD_TEST=OFF"
                        "KUMI_BUILD_DOCUMENTATION=OFF"
              )

# Use KUMI
add_executable(test_kumi ../main.cpp)
target_link_libraries(test_kumi PUBLIC kumi::kumi)
add_test(NAME test_kumi COMMAND test_kumi)
