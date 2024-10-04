#include "Calculator.h"
#include <stdexcept>

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
double Calculator::divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}
