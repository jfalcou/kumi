#!/bin/sh -l

set -e
echo "::group::Running: 'cmake .. -G Ninja -DCMAKE_CXX_COMPILER=$1 -DCMAKE_CXX_FLAGS="$3"  -DCMAKE_EXE_LINKER_FLAGS="$4"'"
mkdir build
cd build
cmake .. -G Ninja -DCMAKE_CXX_COMPILER=$1 -DCMAKE_CXX_FLAGS="$3"  -DCMAKE_EXE_LINKER_FLAGS="$4"
echo "::endgroup::"

echo "::group::Compiling tests"
ninja -j $2
echo "::endgroup::"

echo "::group::Running tests"
ctest --output-on-failure -j $2
echo "::endgroup::"

exit 0
