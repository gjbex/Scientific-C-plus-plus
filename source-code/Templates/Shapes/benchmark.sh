#!/usr/bin/env bash

# This script will build the implementations and perform a benchmark
# using hyperfine. The results will be saved in a file called
# benchmark.json
#
# The script takes to command line arguments:
# 1. The size of the vector to use in the benchmark, default is 1000000, -s <size>
# 2. The compiler to use to build the implementations, default is g++, -c <compiler>
# 3. The file name to store the results, defaults to none, in which case the outpu
#    of hyperfine simply appears on standard output. -o <output file>
#

# make sure scripts stopon first error
set -e

# check if hyperfine is installed
if ! command -v hyperfine &> /dev/null; then
  echo "hyperfine could not be found"
  exit 1
fi

# default values
VECTOR_SIZE=1000000
COMPILER="g++"
OUTPUT_FILE=""

# parse command line arguments
while getopts "s:c:o:" opt; do
  case $opt in
    s) VECTOR_SIZE=$OPTARG ;;
    c) COMPILER=$OPTARG ;;
    o) OUTPUT_FILE=$OPTARG ;;
    \?) echo "Invalid option: -$OPTARG" >&2; exit 1 ;;
  esac
done

# prepare the OUTPUT_FILE variable for hyperfine
if [ -n "$OUTPUT_FILE" ]; then
  OUTPUT_FILE="--export-json $OUTPUT_FILE"
fi

# list of the implementation to compare, separated by space
IMPLEMENTATIONS="Variant Subclasses TypeErasure Crtp"

# make sure the implementation are built for releaes
for impl in $IMPLEMENTATIONS; do
  echo "Building $impl"
  # check if directory exists
  if [ ! -d $impl ]; then
    echo "Directory $impl does not exist"
    exit 1
  fi
  pushd $impl
  cmake -B build/ -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=$COMPILER
  cmake --build build/ --config Release
  popd
done

# create the arguments for hyperfine for each implementation
# The name of the executable is the name of the implementation, but '_' seperated
# lowercase rather than camel case. The executable is in the build directory of
# the implementation, and takes the size of the vector as an argument
ARGS=()
for impl in $IMPLEMENTATIONS; do
  ARGS+=("$impl/build/$(echo ${impl}_shapes.exe | sed -r 's/^([A-Z])/\L\1/' | sed -r 's/([A-Z])/_\L\1/g') $VECTOR_SIZE")
done

printf "\nRunning benchmarks with vector size $VECTOR_SIZE and compiler $COMPILER\n\n"

# run the benchmarks
hyperfine ${OUTPUT_FILE} --warmup 3 "${ARGS[@]}"
