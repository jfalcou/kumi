# Setup

## Direct file download

1. Download the one header file `kumi.hpp` :
    ```
    wget https://raw.githubusercontent.com/jfalcou/kumi/main/include/kumi.hpp
    ```
2. Copy it in the location of your choice.

Using **KUMI** boils down to including `kumi.hpp` and compile using C++20.

``` bash
g++ my_app.cpp -I/path/to/kumi -std=c++20
```

## CMake `FetchContent`

You can also use CMake FetchContent operation and use the `kumi::kumi` library
target that our CMake exports.

``` cmake
##==================================================================================================
## Your project setup
##==================================================================================================
cmake_minimum_required(VERSION 3.2)
project(test_kumi LANGUAGES CXX)

include(FetchContent)

##==================================================================================================
## Fetch Kumi and disable its test targets
##==================================================================================================
set(KUMI_BUILD_TEST    OFF CACHE INTERNAL "OFF")
FetchContent_Declare( kumi
                      GIT_REPOSITORY https://github.com/jfalcou/kumi.git
                      GIT_TAG main
                    )

FetchContent_MakeAvailable(kumi)

##==================================================================================================
## Using Kumi
##==================================================================================================
add_executable( my_app my_app.cpp)
target_link_libraries(my_app kumi::kumi)
```