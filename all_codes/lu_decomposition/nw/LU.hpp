#ifndef LU_HPP
#define LU_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    int Rows, Cols;
    vector<vector<double>> Mat;

    Matrix();
    Matrix(int, int);
    void init();
    void ReadMatricesFromFile(const string&, const string&);
    void PrintMatrix() const;
    void LUDecomposition() const;
    double GetLowerTriangular(const Matrix&, const Matrix&, int, int) const;
    double GetUpperTriangular(const Matrix&, const Matrix&, int, int) const;
};

#endif // LU_HPP
