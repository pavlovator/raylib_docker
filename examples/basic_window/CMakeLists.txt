# Minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(RaylibExampleBasicWindow)

# Specify the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
set(SOURCES main.cpp)

# Add the Raylib package (You might need to set the path if Raylib is not installed globally)
find_package(raylib REQUIRED)

# Include directories for Raylib (if it's not installed globally)
# include_directories(/path/to/raylib/include)

# Add the executable
add_executable(basic_window ${SOURCES})

# Link the Raylib library (and other dependencies)
target_link_libraries(basic_window raylib GL m pthread dl rt X11)
