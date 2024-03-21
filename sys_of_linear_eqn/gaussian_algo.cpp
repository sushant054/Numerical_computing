#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<double>>& mat) {
    for (const auto& row : mat) {
        for (double element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    string fileName_L = "L_3.txt";
    string fileName_R = "R_3.txt";

    ifstream fin;
    fin.open(fileName_L);
    
    if (!fin.is_open()) {
        cerr << "Error opening file: " << fileName_L << endl;
        return 1;
    }

    int rows, cols;
    fin >> rows >> cols;

    cout << "\n rows::" << rows << "\t cols::" << cols << endl;
    
    // Dynamic memory allocation
    vector<vector<double>> mat(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < (cols - 1); j++) {
            fin >> mat[i][j];
        }
    }

    fin.close();

    fin.open(fileName_R);
    
    if (!fin.is_open()) {
        cerr << "Error opening file: " << fileName_R << endl;
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        fin >> mat[i][cols - 1];
    }

    cout << "\n Augmented matrix is :: \n";
    printMatrix(mat);
    fin.close();

    // Gaussian elimination
    for (int r = 0; r < rows; r++) {
        double pivot = mat[r][r];
        for (int c = r; c < cols; c++) {
            mat[r][c] /= pivot;
        }
        for (int k = 0; k < rows; k++) {
            if (k != r) {
                double factor = mat[k][r];
                for (int c = r; c < cols; c++) {
                    mat[k][c] -= factor * mat[r][c];
                }
            }
        }
        cout << "\n++++++++++++++++++++\n";
        printMatrix(mat);
    }
    //back sub.
  cout << "\nSolution:\n";
    for (int i = 0; i < rows; i++) {
        cout << "x" << i + 1 << " = " << mat[i][cols - 1] << endl;
    }

    return 0;
}

