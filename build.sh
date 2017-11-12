#!/bin/bash

mkdir -p build
cd build
cmake .. 
#cmake .. -DINTERNET_DISABLED:BOOL=TRUE
cmake --build . 
cd ..
