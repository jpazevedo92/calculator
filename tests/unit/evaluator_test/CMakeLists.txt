project(EvaluatorTests)

add_executable(EvaluatorTests test_evaluator.cpp)
target_link_libraries(EvaluatorTests ${GTEST_LIBRARIES} pthread EvaluatorLib)