#ifndef LU_HPP
#define LU_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

class Matrix {
private:
    int Rows;
    int Cols;
    vector<vector<double>> Mat;

    double GetLowerTriangular(const Matrix& L, const Matrix& U, int rowIndex, int colIndex) const;
    double GetUpperTriangular(const Matrix& L, const Matrix& U, int rowIndex, int colIndex) const;

public:
    Matrix(); // Default constructor
    Matrix(int r, int c); // Parameterized constructor

    void init(); // Initialize matrix elements to 0
    void ReadMatricesFromFile(const string& fileName_L, const string& fileName_R); // Read matrices from files
    void PrintMatrix() const; // Print the matrix
    void LUDecomposition(Matrix& L, Matrix& U) const; // Perform LU Decomposition
    vector<double> SolveLinearSystem(const vector<double>& b) const; // Solve Ax = b using precomputed LU decomposition
};

#endif // LU_HPP
