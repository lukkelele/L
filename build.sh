#!/usr/bin/env bash

if [ -d build ]; then
    echo "Cleaning build directory"
    rm -rf build
fi

mkdir -p build | exit 1
pushd build
cmake ..
ret=$(make)
popd

echo "
|====================|
|   Build complete   |
|====================|
"
