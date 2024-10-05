#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stdexcept>
#include "Error.h"

class Calculator {
public:
    // Constructor
    Calculator();

    // Basic arithmetic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b, ErrorCode &errorFlag);
    double applyOperation(double a, double b, char op, ErrorCode &errorFlag);
    
};

#endif