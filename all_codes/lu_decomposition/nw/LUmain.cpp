#include <iostream>
#include "lU.hpp"

using namespace std;

int main() {
    Matrix matrix;
    //input 
     string leftMatrixFile = "Bl_3.txt";
    string rightMatrixFile = "Br_3.txt";
    // string leftMatrixFile = "l_3.txt";
    // string rightMatrixFile = "r_3.txt";

    matrix.ReadMatricesFromFile(leftMatrixFile, rightMatrixFile);

    cout << "Matrix after reading from files:" << endl;
    matrix.PrintMatrix();
    matrix.LUDecomposition();

    return 0;
}








 