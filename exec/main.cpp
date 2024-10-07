#include <iostream>
#include <sstream>

#include "Evaluator.h"

// Map error codes to their descriptions
std::unordered_map<ErrorCode, std::string> errorMessages = {
    {ErrorCode::NONE, "No error"},
    {ErrorCode::NO_EXPRESSION, "Error: Expression not exists"},
    {ErrorCode::MISMATCHED_PARENTHESIS, "Error: Mismatched parentheses"},
    {ErrorCode::INVALID_CHARACTER, "Error: Invalid character in the expression"},
    {ErrorCode::MISPLACED_OPERATOR, "Error: Misplaced operator"},
    {ErrorCode::DIVISION_BY_ZERO, "Error: Division by zero"},
    {ErrorCode::INCOMPLETE_EXPRESSION, "Error: Incomplete expression"},
    {ErrorCode::MULTIPLE_VALUES_REMAIN, "Error: Invalid expression. Multiple values remain."}
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }

    // Concatenate the command line arguments into a single expression
    std::ostringstream oss;
    for (int i = 1; i < argc; ++i) {
        oss << argv[i] << " ";
    }
    std::string expression = oss.str();
    
    // Remove trailing whitespace
    expression = expression.substr(0, expression.find_last_not_of(" \n\r\t") + 1);

    int result = 0;
    ErrorCode errorFlag = ErrorCode::NONE;

    // Call evaluate function
    if (evaluate(expression.c_str(), result, errorFlag)) {
        std::cout << "Evaluating: \"" << expression << "\" = " << result << " (true)" << std::endl;
    } else {
        std::cerr << "Evaluating: \"" << expression << "\" = N/A -> " << errorMessages[errorFlag] << " (false)" << std::endl;
    }

    return 0;
}