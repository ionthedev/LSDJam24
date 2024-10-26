#!/bin/bash

# Configure the project with debug symbols
cmake -DCMAKE_BUILD_TYPE=Debug .

# Build the project
cmake --build .

# Check if build was successful
if [ $? -eq 0 ]; then
    # -q suppresses the intro message
    # --ex "set confirm off" disables confirmations
    # -ex run starts the program
    gdb -q -ex "set confirm off" -ex run ./build/LSDJAM
else
    echo "Build failed. Please check the error messages above."
fi
