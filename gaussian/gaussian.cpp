#include "gaussian.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Constructor to initialize and read the matrix from files
GaussianElimination::GaussianElimination(const std::string& fileName_L, const std::string& fileName_R) {
    readMatrix(fileName_L, fileName_R);
}

// Function to read the matrix from files
void GaussianElimination::readMatrix(const std::string& fileName_L, const std::string& fileName_R) {
    std::ifstream fin;

    // Reading L matrix (coefficients)
    fin.open(fileName_L);
    if (!fin.is_open()) {
        throw std::runtime_error("Error opening file: " + fileName_L);
    }
    fin >> rows >> cols;
    mat.resize(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            fin >> mat[i][j];
        }
    }
    fin.close();

    // Reading R matrix (constants)
    fin.open(fileName_R);
    if (!fin.is_open()) {
        throw std::runtime_error("Error opening file: " + fileName_R);
    }
    for (int i = 0; i < rows; i++) {
        fin >> mat[i][cols - 1];
    }
    fin.close();
}

// Function to print the matrix
void GaussianElimination::printMatrix() const {
    for (const auto& row : mat) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

void GaussianElimination::performGaussianElimination() 
{
    for (int r = 0; r < rows; r++) { // Iterate over each row
        // Normalize the pivot row
        double pivot = mat[r][r]; //pivot(diagonal element)
        for (int c = r; c < cols; c++) { // Normalize the entire row by the pivot element
            mat[r][c] /= pivot; // Divide each element in the row by the pivot
        }

        // Eliminate the current column for all other rows
        for (int k = 0; k < rows; k++) { // Iterate over each row again to eliminate the current column
            if (k != r) { // Skip the current pivot row
                double factor = mat[k][r]; // Factor to zero out the current column element in row k
                for (int c = r; c < cols; c++) { // Adjust each element in row k
                    mat[k][c] -= factor * mat[r][c]; // Subtract the scaled pivot row from row k
                }
            }
        }
        // Print matrix after each row operation for debugging purposes
        std::cout << "\n++++++++++++++++++++\n";
        printMatrix(); // Print the current state of the matrix
    }
}

// Function to perform back substitution
void GaussianElimination::backSubstitution() {
    solution.resize(rows); // Resize the solution vector to the number of rows
    for (int i = rows - 1; i >= 0; i--) { // Iterate from the last row upwards
        double sum = 0; // Initialize sum to accumulate known values
        for (int j = i + 1; j < cols - 1; j++) { // Iterate over the columns to the right of the diagonal
            sum += mat[i][j] * solution[j]; // Sum the products of known solutions and their coefficients
        }
        solution[i] = mat[i][cols - 1] - sum; // Solve for the current variable
    }
}

// Function to print the solution
void GaussianElimination::printSolution() const {
    std::cout << "\nSolution:\n";
    for (int i = 0; i < rows; i++) {
        std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    }
}
