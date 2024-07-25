#include <iostream>
#include <fstream>
#include <vector>
#include "gaussian.hpp"

int main() {
    std::string fileName_L = "L_3.txt";
    std::string fileName_R = "R_3.txt";

    std::ifstream fin;
    fin.open(fileName_L);
    
    if (!fin.is_open()) {
        std::cerr << "Error opening file: " << fileName_L << std::endl;
        return 1;
    }

    int rows, cols;
    fin >> rows >> cols;

    std::cout << "\n rows::" << rows << "\t cols::" << cols << std::endl;
    
    // Dynamic memory allocation
    std::vector<std::vector<double>> mat(rows, std::vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < (cols - 1); j++) {
            fin >> mat[i][j];
        }
    }

    fin.close();

    fin.open(fileName_R);
    
    if (!fin.is_open()) {
        std::cerr << "Error opening file: " << fileName_R << std::endl;
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        fin >> mat[i][cols - 1];
    }

    std::cout << "\n Augmented matrix is :: \n";
    printMatrix(mat);
    fin.close();

    // Gaussian elimination
    gaussianElimination(mat);

    // Backsubstitution
    backSubstitution(mat);

    return 0;
}
