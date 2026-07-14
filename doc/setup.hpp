#error This file is for documentation only - DO NOT INCLUDE
/**

  @page  setup  Setup

  @tableofcontents

  @section prerequisit Pre-requisites

  The **KUMI** librarie requires a C++20 compliant compiler. Here are the current minimal compiler version supported:

  | Compiler        | Version            |
  |:----------------|:------------------ |
  | g++             | 14    and  above   |
  | clang++         | 19    and  above   |
  | em++            | 5     and above    |
  | icpx            | 2025  and above    |
  | MSVC            | 19    and  above   |
  | clang-CL        | 19    and above    |
  | AppleClang      | 15    and above    |
  | nvcc            | 13.2.5             |
  | nvc++           | 26.3.0             |

  @section setup-source Install from the source

  Code source of **KUMI** is available on GitHub and can be retrieved via the following command:

  @code
  $ git clone https://github.com/jfalcou/kumi.git
  @endcode

  Once retrieved, you should have a %kumi folder which contains the whole source code.
  
  Then simply use **CMake** to generate the build system and directory for **KUMI**.
  We recommend using Ninja but any build system is fine.
  
  @tab_begin

  @tab{Ninja}

    @code
    $ cmake -S . -B build -G Ninja
    @endcode

  @tab{Visual Studio}

    @code
    $ cmake -S . -B build -G "Visual Studio 17 2022" -A x64 
    @endcode

  @tab_end
  
  Once **CMake** completes, you can use the `install` target to build and install **KUMI**.
  By default, the library will be installed in the `/usr/local` directory, thus requiring
  root privileges.

  @code
  $ sudo cmake --build build --target install
  @endcode

  You can select an alternative installation path by specifying the `CMAKE_INSTALL_PREFIX`
  option at configuration time.

  @code
  $ cmake .. -G <build-system> -DCMAKE_INSTALL_PREFIX=path/to/install
  $ cmake --build build --target install
  @endcode

  Once installed, **KUMI** is usable directly by providing the path to its installed files.

  @section setup-standalone Standalone setup

  You can also use **KUMI** via a single standalone file that can be vendored in your own project without
  having to deal with **KUMI** as a dependency.

  Simply use `wget` to fetch the latest version and place it where you want:

  @code
  wget https://raw.githubusercontent.com/jfalcou/kumi/refs/heads/standalone/kumi.hpp
  @endcode

  Use **KUMI** by just compiling your code with the include path pointing to the location of this single file.

  @section dependency As a CMake dependency
  
  @tab_begin
  
  @tab{FetchContent}

    You can also use CMake FetchContent operation and use the `kumi::kumi` library target that our CMake exports.

    @code{cmake}
    ##==================================================================================================
    ## Your project setup
    ##==================================================================================================
    cmake_minimum_required(VERSION 3.28)
    project(kumi-fetch LANGUAGES CXX)

    include(FetchContent)
    FetchContent_Declare(kumi GIT_REPOSITORY "https://github.com/jfalcou/kumi.git" GIT_TAG main)
    FetchContent_MakeAvailable(kumi)

    add_executable(test_kumi ../main.cpp)
    target_link_libraries(test_kumi PUBLIC kumi::kumi)
    @endcode

  @tab{CPM}

    The **KUMI** library can be setup using [CPM](https://github.com/cpm-cmake/CPM.cmake):

    @code{cmake}
    ##==================================================================================================
    ## Your project setup
    ##==================================================================================================
    cmake_minimum_required(VERSION 3.28)
    project(kumi-cpm LANGUAGES CXX)

    # Setup CPM - See https://github.com/cpm-cmake/CPM.cmake#adding-cpm
    include(cpm.cmake)

    CPMAddPackage ( NAME kumi
                    GIT_REPOSITORY "https://github.com/jfalcou/kumi.git"
                    OPTIONS "KUMI_BUILD_TEST OFF"
                  )

    add_executable(test_kumi ../main.cpp)
    target_link_libraries(test_kumi PUBLIC kumi::kumi)
    @endcode
  
  @tab_end

**/
