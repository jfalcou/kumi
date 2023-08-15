##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.22)
project(kumi-install-test LANGUAGES CXX)
enable_testing()

find_package(kumi CONFIG REQUIRED)
add_executable(test_kumi ../main.cpp)
target_link_libraries(test_kumi PUBLIC kumi::kumi)
add_test(NAME test_kumi COMMAND test_kumi)
