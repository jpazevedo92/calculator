#include "Calculator.h"

// Constructor
Calculator::Calculator() {}

// Addition
double Calculator::add(double a, double b) {
    return a + b;
}

// Subtraction
double Calculator::subtract(double a, double b) {
    return a - b;
}

// Multiplication
double Calculator::multiply(double a, double b) {
    return a * b;
}

// Division (handles division by zero)
double Calculator::divide(double a, double b, ErrorCode &errorFlag) {
    if (b == 0.0) {
        errorFlag = ErrorCode::DIVISION_BY_ZERO;
        return 0;
    }
    return a / b;
}

double Calculator::applyOperation(double a, double b, char op, ErrorCode &errorFlag) {
    errorFlag=ErrorCode::NONE;
    switch(op) {
        case '+': return add(a,b);
        case '-': return subtract(a,b);
        case '*': return multiply(a,b);
        case '/': return divide(a,b, errorFlag);
        default: 
            errorFlag = ErrorCode::INVALID_CHARACTER;
    }
    return 0;
}
