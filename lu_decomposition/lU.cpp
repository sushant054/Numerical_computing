#include "lU.hpp"

Matrix::Matrix() : Rows(0), Cols(0) {}

Matrix::Matrix(int r, int c) : Rows(r), Cols(c) {
    this->Mat.resize(Rows, vector<double>(Cols, 0));
}

void Matrix::init() {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            Mat[i][j] = 0;
        }
    }
}

void Matrix::ReadMatricesFromFile(const string& fileName_L, const string& fileName_R) {
    ifstream fin;

    fin.open(fileName_L);
    if (!fin.is_open()) {
        throw runtime_error("Error opening file: " + fileName_L);
    }
    fin >> Rows >> Cols;
    Mat.resize(Rows, vector<double>(Cols));
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols - 1; j++) {
            fin >> Mat[i][j];
        }
    }
    fin.close();

    fin.open(fileName_R);
    if (!fin.is_open()) {
        throw runtime_error("Error opening file: " + fileName_R);
    }
    for (int i = 0; i < Rows; i++) {
        fin >> Mat[i][Cols - 1];
    }
    fin.close();
}

void Matrix::PrintMatrix() const {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }
}

double Matrix::GetLowerTriangular(const Matrix& L, const Matrix& U, int rowIndex, int colIndex) const {
    if (rowIndex < colIndex) return 0;

    double sum = 0;
    for (int k = 0; k < colIndex; k++) {
        sum += L.Mat[rowIndex][k] * U.Mat[k][colIndex];
    }
    return Mat[rowIndex][colIndex] - sum;
}

double Matrix::GetUpperTriangular(const Matrix& L, const Matrix& U, int rowIndex, int colIndex) const {
    if (rowIndex > colIndex) return 0;
    if (rowIndex == colIndex) return 1;

    double sum = 0;
    for (int k = 0; k < rowIndex; k++) {
        sum += L.Mat[rowIndex][k] * U.Mat[k][colIndex];
    }
    return (Mat[rowIndex][colIndex] - sum) / L.Mat[rowIndex][rowIndex];
}

void Matrix::LUDecomposition(Matrix& L, Matrix& U) const {
    L = Matrix(Rows, Cols);
    U = Matrix(Rows, Cols);

    for (int rowIndex = 0; rowIndex < Rows; rowIndex++) {
        for (int colIndex = 0; colIndex < Cols; colIndex++) {
            if (colIndex >= rowIndex) {
                U.Mat[rowIndex][colIndex] = GetUpperTriangular(L, U, rowIndex, colIndex);
            }
            if (colIndex <= rowIndex) {
                L.Mat[rowIndex][colIndex] = GetLowerTriangular(L, U, rowIndex, colIndex);
            }
        }
    }
}

vector<double> Matrix::SolveLinearSystem(const vector<double>& b) const {
    vector<double> x(Rows, 0);
    vector<double> y(Rows, 0);

    // Solve Ly = b for y
    for (int i = 0; i < Rows; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += Mat[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / Mat[i][i];
    }

    // Solve Ux = y for x
    for (int i = Rows - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < Rows; j++) {
            sum += Mat[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / Mat[i][i];
    }

    return x;
}
