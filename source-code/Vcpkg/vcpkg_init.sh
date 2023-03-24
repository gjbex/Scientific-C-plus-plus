#!/usr/bin/env bash

BUILD_DIR=./build
VCPKG_DIR=/home/gjb/vcpkg/

mkdir -p "$BUILD_DIR"

cmake -B "$BUILD_DIR" \
      -S . \
      -DCMAKE_TOOLCHAIN_FILE=$VCPKG_DIR/scripts/buildsystems/vcpkg.cmake
