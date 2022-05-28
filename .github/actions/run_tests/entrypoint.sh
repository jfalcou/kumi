#!/bin/sh -l

echo "::group::Running: 'cmake .. -G Ninja -DCMAKE_CXX_FLAGS="$1" $2'"
mkdir build
cd build
cmake .. -G Ninja -DCMAKE_CXX_COMPILER="$1"
echo "::endgroup::"

echo "::group::Compiling test" ;
ninja -k 0 ;
if [ "$?" -ne "0" ]
then
  echo "::error Tests can not be compiled!" ;
  exit 1;
fi
echo "::endgroup::" ;

echo "::group::Running test" ;
ctest ;
if [ "$?" -ne "0" ]
then
  echo "::error Errors running tests!" ;
  exit 1;
fi
echo "::endgroup::" ;

exit 0;
