#include <iostream>
#include "gaussian.hpp"

int main() {
    try {
        std::string fileName_L = "L_3.txt";
        std::string fileName_R = "R_3.txt";

        GaussianElimination solver(fileName_L, fileName_R);

        std::cout << "\nAugmented matrix is:\n";
        solver.printMatrix();

        // Gaussian elimination
        solver.performGaussianElimination();

        // Back substitution
        solver.backSubstitution();

        // Print solution
        solver.printSolution();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
