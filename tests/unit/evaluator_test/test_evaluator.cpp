#include <gtest/gtest.h>
#include "Evaluator.h" // Change this to the appropriate header for your evaluate function

// Test cases for the evaluate function
TEST(EvaluateTest, BasicOperations) {
    int result;
    ErrorCode errorFlag;

    // Valid expressions
    EXPECT_TRUE(evaluate("1 + 3", result, errorFlag));
    EXPECT_EQ(result, 4);

    EXPECT_TRUE(evaluate("(1 + 3) * 2", result, errorFlag));
    EXPECT_EQ(result, 8);

    EXPECT_TRUE(evaluate("(4 / 2) + 6", result, errorFlag));
    EXPECT_EQ(result, 8);

    EXPECT_TRUE(evaluate("4 + (12 / (1 * 2))", result, errorFlag));
    EXPECT_EQ(result, 10);
}

TEST(EvaluateTest, MissingBrackets) {
    int result;
    ErrorCode errorFlag;

    // Missing closing bracket
    EXPECT_FALSE(evaluate("(1 + (12 * 2)", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::MISMATCHED_PARENTHESIS);
}

TEST(EvaluateTest, InvalidCharacters) {
    int result;
    ErrorCode errorFlag;

    EXPECT_FALSE(evaluate("1 + @ 3", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::INVALID_CHARACTER);
}

TEST(EvaluateTest, MisplacedOperators) {
    int result;
    ErrorCode errorFlag;

    EXPECT_FALSE(evaluate("1 + + 3", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::MISPLACED_OPERATOR);

    EXPECT_FALSE(evaluate("1 * (2 + )", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::INCOMPLETE_EXPRESSION);
}

TEST(EvaluateTest, DivisionByZero) {
    int result;
    ErrorCode errorFlag;

    EXPECT_FALSE(evaluate("4 / 0", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::DIVISION_BY_ZERO);
}

TEST(EvaluateTest, IncompleteExpressions) {
    int result;
    ErrorCode errorFlag;

    EXPECT_FALSE(evaluate("1 +", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::INCOMPLETE_EXPRESSION);

    EXPECT_FALSE(evaluate("()", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::MISMATCHED_PARENTHESIS);
}

TEST(EvaluateTest, NegativeNumbers) {
    int result;
    ErrorCode errorFlag;

    EXPECT_TRUE(evaluate("-1 + 3", result, errorFlag));
    EXPECT_EQ(result, 2);

    EXPECT_TRUE(evaluate("(-1 + 3) * 2", result, errorFlag));
    EXPECT_EQ(result, 4);
}

TEST(EvaluateTest, MultipleValuesRemain) {
    int result;
    ErrorCode errorFlag;

    EXPECT_FALSE(evaluate("1 + 2 +", result, errorFlag));
    EXPECT_EQ(errorFlag, ErrorCode::INCOMPLETE_EXPRESSION);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
