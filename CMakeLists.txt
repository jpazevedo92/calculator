# Minimum CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(SonyCalculator LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

OPTION(WITH_TESTS "Generate unittests binary" OFF)

# Add the subdirectory where the library for calculator is
add_subdirectory(calc)

# Add the subdirectory where the library for calculator is
add_subdirectory(evaluator)

# Add the subdirectory where the executer for calculator is
add_subdirectory(exec)

if(WITH_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_subdirectory(tests)
endif()