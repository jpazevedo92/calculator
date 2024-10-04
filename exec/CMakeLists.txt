project(SonyCalculator)

set(
    SOURCES
    main.cpp
)

set(
    LIBS
    CalculatorLib
)

set(
    PRIV_LIBS
    CalculatorLib
)


# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the Calculator library to the executable
target_link_libraries(${PROJECT_NAME} PUBLIC ${PRIV_LIBS})