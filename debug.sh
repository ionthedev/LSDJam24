#!/bin/bash

# Configure the project with debug symbols
cmake -DCMAKE_BUILD_TYPE=Debug .

# Build the project
cmake --build .

# Check if build was successful
if [ $? -eq 0 ]; then
    # Run the executable with gdb
    gdb -ex run ./LSDJAM
else
    echo "Build failed. Please check the error messages above."
fi

# Return to the original directory
