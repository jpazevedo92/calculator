project(SonyCalculator)

set(
    SOURCES
    main.cpp
)

set(
    PRIV_LIBS
    EvaluatorLib
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the Calculator library to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE ${PRIV_LIBS})