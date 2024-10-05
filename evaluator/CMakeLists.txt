project(EvaluatorLib)

set(
    EVAL_LIB_DIR
    ${CMAKE_SOURCE_DIR}/evaluator
)

set(
    SOURCES
    ${EVAL_LIB_DIR}/Evaluator.cpp
)

set(
    LIBS
    CalculatorLib
)

# Create a static library
add_library(${PROJECT_NAME} STATIC)

# Add the Evaluator source files
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

# Link the Calculator and Evaluator libraries together
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBS} )

#Include directories
target_include_directories(${PROJECT_NAME} PUBLIC .)