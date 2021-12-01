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
