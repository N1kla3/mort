#!/bin/bash

rm -rf build && mkdir build && cmake -G Ninja -DMORT_DEV=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B ./build -S .
cmake --build ./build -j 10 && cp build/compile_commands.json ./
