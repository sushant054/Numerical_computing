#ifndef MATRIX_CLASS_HPP
#define MATRIX_CLASS_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

class Matrix {
public:
    double** mat;
    int rows, cols;

    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& T);
    ~Matrix();

    void display();
    void readMatrixFromFile(const string& filename);
    bool isDiagonallyDominant();
    bool makeDiagonallyDominant();
    int getDDRow(int row);
    void swapRows(int r1, int r2);
    void guassSeidel();
    vector<Matrix> lowerUpperDecomposition();
    double computeL(double** mat, double** L, double** U, int row, int col);
    double computeU(double** mat, double** U, double** L, int row, int col);
    bool isSymmetric();
    vector<vector<double>> transpose();
};

#endif
