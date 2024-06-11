#include <iostream>
#include <vector>
#include "Choleski.hpp"
#include <fstream>
#include <cmath>
using namespace std;

// Default constructor
Matrix::Matrix() {
    cout << "Cholesky Decomposition... @ " << this << endl;
}

// Parameterized constructor
Matrix::Matrix(int r, int c) {
    this->Rows = r;
    this->Cols = c;
    this->Mat.resize(Rows, std::vector<double>(Cols, 0));
}

// Function to read the matrix from a file
void Matrix::ReadMatrixFromFile(string MatrixFile) {
    ifstream Fin;
    Fin.open(MatrixFile); // Open the file
    if (!Fin) {
        cout << "Error: Unable to open matrix file!" << endl;
        exit(1); // Exit if the file cannot be opened
    }

    Fin >> this->Rows >> this->Cols; // Read the number of rows and columns from the file
    this->Mat.resize(Rows, std::vector<double>(Cols, 0)); // Resize the matrix

    cout << "\n No of rows::" << Rows << "\tNo of cols::" << Cols << endl;

    // Read the matrix elements from the file
    for (int i = 0; i < this->Rows; i++) {
        for (int j = 0; j < this->Cols; j++) {
            Fin >> this->Mat[i][j];
        }
    }
    Fin.close(); // Close the file
}

// Function to print the matrix
void Matrix::PrintMatrix() {
    for (int i = 0; i < Mat.size(); i++) {
        for (int j = 0; j < Mat[i].size(); j++) {
            cout << Mat[i][j] << " "; // Print each element followed by a space
        }
        cout << endl; // New line for each row
    }
}

// Function to check if the matrix is symmetric
bool Matrix::isSymmetric() {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (i > j) { // Only check lower triangular part
                if (Mat[i][j] != Mat[j][i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// Function to get the diagonal element for the Cholesky decomposition
double Matrix::getDiagonalElement(Matrix LowerTriangularMatrix, int RowIndex) {
    double Ans1 = Mat[RowIndex][RowIndex];
    double temp = 0.0;
    for (int k = 0; k < RowIndex; k++) {
        temp += LowerTriangularMatrix.Mat[RowIndex][k] * LowerTriangularMatrix.Mat[RowIndex][k];
    }
    double Ans2 = sqrt(Ans1 - temp); // Calculate the diagonal element
    return Ans2;
}

// Function to get the lower triangular matrix element for the Cholesky decomposition
double Matrix::getLowerTriangularMatrix(Matrix LowerTriangularMatrix, int RowIndex, int ColIndex) {
    double Ans1 = Mat[RowIndex][ColIndex];
    double temp = 0.0;
    double Ans2 = LowerTriangularMatrix.Mat[ColIndex][ColIndex];
    for (int k = 0; k < ColIndex; k++) {
        temp += LowerTriangularMatrix.Mat[RowIndex][k] * LowerTriangularMatrix.Mat[ColIndex][k];
    }
    double Ans = (Ans1 - temp) / Ans2; // Calculate the lower triangular element
    return Ans;
}

// Function to get the transpose of the lower triangular matrix
Matrix Matrix::LowerMatrixTranspose(Matrix LowerTriangularMatrix) {
    Matrix LowerTriangularMatrixTranspose(this->Rows, this->Cols);
    for (int RowIndex = 0; RowIndex < Rows; RowIndex++) {
        for (int ColIndex = 0; ColIndex < Rows; ColIndex++) {
            LowerTriangularMatrixTranspose.Mat[RowIndex][ColIndex] = LowerTriangularMatrix.Mat[ColIndex][RowIndex];
        }
    }
    return LowerTriangularMatrixTranspose;
}

// Function to perform Cholesky decomposition
void Matrix::CholeskyDecomposition() {
    if (isSymmetric()) {
        cout << "The matrix is symmetric." << endl;
    } else {
        cout << "The matrix is not symmetric." << endl;
        return;
    }

    Matrix LowerTriangularMatrix(this->Rows, this->Cols);
    int RowIndex, ColIndex;

    // Calculate the elements of the lower triangular matrix
    for (RowIndex = 0; RowIndex < Rows; RowIndex++) {
        cout << "\n rowIndex :: " << RowIndex << endl;
        for (ColIndex = 0; ColIndex <= RowIndex; ColIndex++) {
            cout << "\n colIndex :: " << ColIndex << endl;
            if (RowIndex == ColIndex) {
                LowerTriangularMatrix.Mat[RowIndex][RowIndex] = getDiagonalElement(LowerTriangularMatrix, RowIndex);
            } else if (ColIndex < RowIndex) {
                LowerTriangularMatrix.Mat[RowIndex][ColIndex] = getLowerTriangularMatrix(LowerTriangularMatrix, RowIndex, ColIndex);
            }
            cout << "Lower Triangular Matrix::" << endl;
            LowerTriangularMatrix.PrintMatrix();
        }
    }
    // Get the transpose of the lower triangular matrix
    Matrix LowerTriangularMatrixTranspose = LowerMatrixTranspose(LowerTriangularMatrix);
    cout << "Transpose of Lower Triangular Matrix::" << endl;
    LowerTriangularMatrixTranspose.PrintMatrix();
}



