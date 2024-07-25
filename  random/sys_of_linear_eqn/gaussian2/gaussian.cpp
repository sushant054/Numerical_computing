#include "gaussian.hpp"
#include <iostream>

void printMatrix(std::vector<std::vector<double>>& mat) {
    for (const auto& row : mat) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

void gaussianElimination(std::vector<std::vector<double>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    for (int r = 0; r < rows; r++) {
        double pivot = mat[r][r];
        for (int c = r; c < cols; c++) {
            mat[r][c] /= pivot;
        }
        for (int k = 0; k < rows; k++) {
            if (k != r) {
                double factor = mat[k][r];
                for (int c = r; c < cols; c++) {
                    mat[k][c] -= factor * mat[r][c];
                }
            }
        }
        std::cout << "\n++++++++++++++++++++\n";
        printMatrix(mat);
    }
}

void backSubstitution(std::vector<std::vector<double>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    std::vector<double> solution(rows);
    for (int i = rows - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < cols - 1; j++) {
            sum += mat[i][j] * solution[j];
        }
        solution[i] = mat[i][cols - 1] - sum;
    }

    // Print solution
    std::cout << "\nSolution:\n";
    for (int i = 0; i < rows; i++) {
        std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    }
}
