#include <iostream>
#include "Calculator.h"

int main(int argc, char* argv[]) {
    Calculator calc;

    // Check if any command-line arguments were passed
    if (argc == 1) {
        std::cout << "No arguments provided!" << std::endl;
        return 1;
    }
    
    // Perform and print basic operations
    std::cout << "Addition: " << calc.add(std::stod(argv[1]), std::stod(argv[2])) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(std::stod(argv[1]), std::stod(argv[2])) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(std::stod(argv[1]), std::stod(argv[2])) << std::endl;
    std::cout << "Division: " << calc.divide(std::stod(argv[1]), std::stod(argv[2])) << std::endl;

    return 0;
}