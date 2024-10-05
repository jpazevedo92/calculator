project(CalculatorLib)

set(
    CALC_LIB_DIR
    ${CMAKE_SOURCE_DIR}/calc
)

set(
    SOURCES
    ${CALC_LIB_DIR}/Calculator.cpp
)

set(
    PRIV_LIBS
    ${CMAKE_SOURCE_DIR}/error/Error.h
)

# Create a static library
add_library(${PROJECT_NAME} STATIC)

# Add the Calculator source files
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

# Link the Calculator and Error libraries together
target_link_libraries(${PROJECT_NAME} PUBLIC ${PRIV_LIBS} )

#Include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/error)
target_include_directories(${PROJECT_NAME} PUBLIC .)
