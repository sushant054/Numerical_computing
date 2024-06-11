#include <bits/stdc++.h>
using namespace std;

#include <vector>

class Matrix
{
public:
    int Rows, Cols;
    std::vector<std::vector<double>> Mat;
    //constructor
    Matrix();
    Matrix(int, int);

    void ReadMatrixFromFile(std::string);
    void PrintMatrix();
    bool isSymmetric();
    double getDiagonalElement(Matrix, int);
    double getLowerTriangularMatrix(Matrix, int, int);
    void CholeskyDecomposition();
    Matrix LowerMatrixTranspose(Matrix);

    // void getLowerTriangularMatrix();
};
