#include "MatrixClass.hpp"

// Default constructor
Matrix::Matrix() {
    mat = nullptr; // Initialize matrix pointer to null
    rows = cols = 0; // Initialize rows and columns to 0
}

// Parameterized constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    mat = new double* [rows]; // Allocate memory for rows
    for (int t = 0; t < rows; t++) {
        mat[t] = new double[cols]; // Allocate memory for columns
    }
    // Initialize matrix elements to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }
}

// Copy constructor
Matrix::Matrix(const Matrix& T) {
    rows = T.rows;
    cols = T.cols;
    mat = new double*[rows]; // Allocate memory for rows
    for (int t = 0; t < rows; t++) {
        mat[t] = new double[cols]; // Allocate memory for columns
    }
    // Copy elements from the source matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = T.mat[i][j];
        }
    }
}

// Function to display the matrix
void Matrix::display() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << mat[i][j] << "\t"; // Print each element
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

// Function to read matrix from a file
void Matrix::readMatrixFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1); // Exit if file cannot be opened
    }

    fin >> rows >> cols; // Read the number of rows and columns

    mat = new double*[rows]; // Allocate memory for rows
    for (int t = 0; t < rows; t++) {
        mat[t] = new double[cols]; // Allocate memory for columns
    }

    // Read the matrix elements from the file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fin >> mat[i][j];
        }
    }
    fin.close(); // Close the file
}

// Function to check if the matrix is diagonally dominant
bool Matrix::isDiagonallyDominant() {
    if (mat != nullptr) {
        for (int r = 0; r < rows; r++) {
            double sum = 0.0;
            for (int c = 0; c < cols - 1; c++) {
                if (r != c) {
                    sum += fabs(mat[r][c]); // Sum of the absolute values of non-diagonal elements in the row
                }
            }
            if (fabs(mat[r][r]) <= sum) // Check if diagonal element is greater than the sum of non-diagonal elements
                return false;
        }
        return true;
    }
    return false;
}

// Function to make the matrix diagonally dominant
bool Matrix::makeDiagonallyDominant() {
    for (int r = 0; r < rows; r++) {
        double s = 0.0;
        for (int c = 0; c < cols - 1; c++) {
            if (r != c)
                s += fabs(mat[r][c]); // Sum of the absolute values of non-diagonal elements in the row
        }
        if (s > fabs(mat[r][r])) { // If row is not diagonally dominant
            int index = getDDRow(r); // Find a row to swap
            if (index != -1)
                swapRows(r, index); // Swap rows to make the matrix diagonally dominant
            else
                return false;
        }
    }
    return true;
}

// Function to find a diagonally dominant row to swap
int Matrix::getDDRow(int row) {
    for (int i = row + 1; i < rows; i++) {
        double s = 0.0;
        for (int j = 0; j < cols - 1; j++) {
            if (row != j)
                s += fabs(mat[i][j]); // Sum of the absolute values of non-diagonal elements in the row
        }
        if (fabs(mat[i][row]) >= s) // Check if the row is diagonally dominant
            return i; // Return the index of the row
    }
    std::cout << "No Diagonally Dominant row found after Row " << row << std::endl;
    return -1; // Return -1 if no diagonally dominant row is found
}

// Function to swap two rows
void Matrix::swapRows(int r1, int r2) {
    for (int i = 0; i < cols; i++) {
        std::swap(mat[r1][i], mat[r2][i]); // Swap elements of the two rows
    }
}

// Destructor to deallocate memory
Matrix::~Matrix() {
    if (mat != nullptr) {
        for (int j = 0; j < rows; j++) {
            delete[] mat[j]; // Delete each row
        }
        delete[] mat; // Delete the row pointers
    }
}

// Function to perform Gauss-Jacobi iteration
void Matrix::gaussJacobi() {
    if (!isDiagonallyDominant())
        makeDiagonallyDominant(); // Ensure the matrix is diagonally dominant
    bool flag = true;
    int count = 0;
    double var[cols - 1], prev[cols - 1], sum = 0.0;

    // Initialize the variables
    for (int i = 0; i < cols - 1; i++) {
        var[i] = prev[i] = 0;
    }

    // Iteratively apply the Gauss-Jacobi method
    while (flag) {
        for (int i = 0; i < cols - 1; i++) {
            prev[i] = var[i]; // Save the current values
        }

        // Update each variable
        for (int r = 0; r < rows; r++) {
            double lhs = 0.0;
            for (int c = 0; c < cols - 1; c++) {
                if (r != c) {
                    lhs += mat[r][c] * prev[c]; // Calculate the sum of the known terms
                }
            }
            lhs = (-1) * lhs + mat[r][cols - 1]; // Calculate the right-hand side
            var[r] = lhs / mat[r][r]; // Update the variable
        }

        sum = 0.0;
        for (int i = 0; i < cols - 1; i++) {
            sum += pow(prev[i] - var[i], 2); // Calculate the difference between the old and new values
        }

        if (sqrt(sum) <= 1e-6) { // Check if the difference is below the tolerance
            flag = false; // Stop the iteration
        }
        count++; // Increment the iteration count
    }
    std::cout << "Iterations for Jacobi ::" << count << std::endl;
    for (int i = 0; i < cols - 1; i++) {
        std::cout << var[i] << std::endl; // Print the result
    }
}
