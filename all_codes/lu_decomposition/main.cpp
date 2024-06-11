#include <iostream>
#include "lU.hpp"

using namespace std;

int main() {
    try {
        // Example usage
        string leftMatrixFile = "A.txt";
        string rightMatrixFile1 = "r1.txt";
        string rightMatrixFile2 = "r2.txt";

        // Create an instance of the Matrix class
        Matrix matrix;

        // Read the coefficient matrix and first RHS vector
        matrix.ReadMatricesFromFile(leftMatrixFile, rightMatrixFile1);

        // Perform LU decomposition
        Matrix L, U;
        matrix.LUDecomposition(L, U);

        // Example of solving with the first RHS vector
        vector<double> b1 = {1, 2, 3}; // Initialize with appropriate values for testing
        vector<double> x1 = matrix.SolveLinearSystem(b1);

        // Print the solution for the first RHS vector
        cout << "Solution for RHS1:" << endl;
        for (double val : x1) {
            cout << val << " ";
        }
        cout << endl;

        // Read the second RHS vector
        matrix.ReadMatricesFromFile(leftMatrixFile, rightMatrixFile2);

        // Example of solving with the second RHS vector
        vector<double> b2 = {4, 5, 6}; // Initialize with appropriate values for testing
        vector<double> x2 = matrix.SolveLinearSystem(b2);

        // Print the solution for the second RHS vector
        cout << "Solution for RHS2:" << endl;
        for (double val : x2) {
            cout << val << " ";
        }
        cout << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
