#include <iostream>

int main(int argc, char* argv[]) {
    // Check if any command-line arguments were passed
    if (argc == 1) {
        std::cout << "No arguments provided!" << std::endl;
        return 1;
    }

    // Loop through and print all the arguments passed
    std::cout << "Number of arguments: " << argc - 1 << std::endl;
    for (int i = 1; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}