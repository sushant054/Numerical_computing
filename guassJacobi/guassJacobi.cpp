#include "MatrixClass.hpp"

int main() {
    Matrix mat;
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    mat.readMatrixFromFile(filename);

    mat.display();

    mat.gaussJacobi();

    return 0;
}
