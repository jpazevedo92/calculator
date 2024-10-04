project(CalculatorLib)

set(
    CALC_LIB_DIR
    ${CMAKE_SOURCE_DIR}/calc
)

set(
    SOURCES
    ${CALC_LIB_DIR}/Calculator.cpp
)

# Create a static library
add_library(${PROJECT_NAME} STATIC)

# Add the Calculator source files
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

#Include directories
target_include_directories(${PROJECT_NAME} PUBLIC .)
