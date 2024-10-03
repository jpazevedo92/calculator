# Minimum CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(SonyCalculator LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(SonyCalculator exec/main.cpp)