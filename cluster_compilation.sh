#!/usr/bin/env bash

module load CMake/3.7.1-intel-2016b

rm -rf build && mkdir build && cd build && cmake .. -DCMAKE_C_COMPILER=icc -DCMAKE_CXX_COMPILER=icpc && make

