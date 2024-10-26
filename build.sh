#!/bin/bash

# Build the project
cmake --build .
mv LSDJAM ./build

echo "Build complete. Executable is in the 'build' directory."
