# Sony Calculator

## Overview

The Sony Calculator is a simple mathematical expression evaluator implemented in C++. It supports basic arithmetic operations, including addition, subtraction, multiplication, and division. The calculator can handle nested expressions, negative numbers, and common error cases. 

## Features

- Evaluate mathematical expressions with:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- Support for nested expressions using parentheses (`(` and `)`)
- Handle negative numbers
- Error detection for:
  - Mismatched parentheses
  - Invalid characters
  - Misplaced operators
  - Division by zero
  - Incomplete expressions
  - Multiple values remaining at the end of evaluation

## Getting Started

### Prerequisites

- C++11 or later
- CMake for building the project
- Google Test for unit testing (optional)

### Installation

1. **Clone the repository** (if applicable):

   ```bash
   git clone https://github.com/jpazevedo92/calculator.git
   cd calculator
   mkdir build && cd build
   
   ```
   
2. **Build and run**:
    ```bash
    cd calculator
    mkdir build && cd build
    
    # To build just executable
    cmake ..

    # To build with unit tests
    cmake -DWITH_TESTS=ON ..

    make

   # To run the executable
   ./exec/SonyCalculator "<expression to test>"

    # To run the tests
   ./tests/unit/EvaluatorTests
