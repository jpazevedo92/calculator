#include "Evaluator.h"

// int precedence(char op) {
//     if(op == '+' || op == '-') {
//         return 1;
//     }
//     if(op == '*' || op == '/') {
//         return 2;
//     }
//     return 0;
// }

// Recursive function to evaluate expressions, especially those within parentheses
bool evaluateExpression(const char *expression, int &result, int &i, ErrorCode &errorFlag) {
    Calculator calculator;
    std::vector<char> operators;    // Vector to store operators (+, -, *, /)
    std::vector<int> values;        // Vector to store operands
    
    bool expectingOperand = true;  // Flag to determine if an operand is expected

    while (expression[i] != '\0') {
        // Skip whitespace
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        // Handle opening parenthesis
        if (expression[i] == '(') {
            i++; // Move past '('
            int subResult;
            if (!evaluateExpression(expression, subResult, i, errorFlag)) {
                return false; // Error in sub-expression
            }
            values.push_back(subResult);
            expectingOperand = false;
            continue;
        }

        // Handle closing parenthesis
        if (expression[i] == ')') {
            i++; // Move past ')'
            if (expectingOperand) {
                errorFlag = ErrorCode::MISPLACED_OPERATOR; // Could be a misplaced operator
                return false;
            }
            break; // Return to the caller to handle
        }

        // Handle numbers (including negative numbers)
        if (isdigit(expression[i]) || (expression[i] == '-' && expectingOperand)) {
            int sign = 1;
            if (expression[i] == '-') {
                sign = -1;
                i++; // Move past '-'
                if (!isdigit(expression[i])) {
                    errorFlag = ErrorCode::MISPLACED_OPERATOR;
                    return false;
                }
            }

            int num = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            values.push_back(sign * num);
            expectingOperand = false;
            continue;
        }

        // Handle operators
        if (strchr("+-*/", expression[i]) != nullptr) {
            char currentOp = expression[i];
            i++; // Move past operator
            
            if (expectingOperand) {
                errorFlag = ErrorCode::MISPLACED_OPERATOR;
                return false;
            }

            // Push the operator to the operators vector
            operators.push_back(currentOp);
            expectingOperand = true; // Next should be an operand
            continue;
        }

        // Invalid character encountered
        errorFlag = ErrorCode::INVALID_CHARACTER;
        return false;
    }

    // Check if we finished processing with open parentheses
    if (expectingOperand && !operators.empty()) {
        errorFlag = ErrorCode::INCOMPLETE_EXPRESSION; // No value for the last operator
        return false;
    }

    // Apply remaining operators
    while (!operators.empty()) {
        if (values.size() < 2) {
            errorFlag = ErrorCode::INCOMPLETE_EXPRESSION;
            return false;
        }

        int b = values.back(); values.pop_back();
        int a = values.back(); values.pop_back();
        char op = operators.back(); operators.pop_back();
        
        int res = calculator.applyOperation(a, b, op, errorFlag);
        if (errorFlag != ErrorCode::NONE) {
            return false;
        }
        values.push_back(res);
    }

    // The final result should be the only value in the vector
    if (values.size() != 1) {
        errorFlag = ErrorCode::MULTIPLE_VALUES_REMAIN;
        return false;
    }

    result = values.back();
    return true;
}

bool evaluate(const char *expression, int &result, ErrorCode &errorFlag) {
    int index = 0;
    bool success = evaluateExpression(expression, result, index, errorFlag);
    
    // After evaluation, ensure that we've processed the entire expression
    while (expression[index] != '\0') {
        if (isspace(expression[index])) {
            index++;
            continue;
        }
        // If there's any non-space character left, it's an error
        errorFlag = ErrorCode::INVALID_CHARACTER;
        return false;
    }

    // Check for unmatched parentheses
    if (errorFlag == ErrorCode::NONE) {
        int parenthesisCount = 0; // Count of open parentheses
        for (int i = 0; expression[i] != '\0'; ++i) {
            if (expression[i] == '(') {
                parenthesisCount++;
            } else if (expression[i] == ')') {
                parenthesisCount--;
            }
        }
        if (parenthesisCount != 0) {
            errorFlag = ErrorCode::MISMATCHED_PARENTHESIS;
            return false;
        }
    }

    return success && (errorFlag == ErrorCode::NONE);
}
