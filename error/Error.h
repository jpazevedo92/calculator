#ifndef ERROR_H
#define ERROR_H

#include <unordered_map>
#include <iostream>

// Define error codes
enum class ErrorCode {
    NONE,                       // No error
    NO_EXPRESSION,             // Expression not exists (e.g., ())
    MISMATCHED_PARENTHESIS,    // Mismatched parentheses
    INVALID_CHARACTER,         // Invalid character in expression
    MISPLACED_OPERATOR,        // Operator in an invalid position
    DIVISION_BY_ZERO,          // Division by zero
    INCOMPLETE_EXPRESSION,     // Incomplete expression (e.g., missing operand)
    MULTIPLE_VALUES_REMAIN     // Multiple values remain at the end (invalid expression)
};


#endif // ERROR_H