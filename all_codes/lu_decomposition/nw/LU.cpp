#include "lU.hpp" // Include the header file for the Matrix class

// Default constructor
Matrix::Matrix() : Rows(0), Cols(0) {
    std::cout << "LU Decomposition " << this << std::endl; // Print a message indicating that an instance of Matrix has been created
}

// Parameterized constructor
Matrix::Matrix(int r, int c) : Rows(r), Cols(c) {
    this->Mat.resize(Rows, std::vector<double>(Cols, 0)); // Resize the matrix to have 'r' rows and 'c' columns, initialized to 0
}

// Function to initialize the matrix elements to 0
void Matrix::init() {
    for (size_t i = 0; i < Rows; i++) { // Loop over each row
        for (size_t j = 0; j < Cols; j++) { // Loop over each column in the current row
            Mat[i][j] = 0; // Set each element to 0
        }
    }
}

// Function to read the matrices from files
void Matrix::ReadMatricesFromFile(const string& fileName_L, const string& fileName_R) {
    ifstream fin; // Create an ifstream object for file input

    // Reading L matrix (coefficients)
    fin.open(fileName_L); // Open the file containing the L matrix
    if (!fin.is_open()) { // Check if the file was successfully opened
        throw runtime_error("Error opening file: " + fileName_L); // Throw an error if the file cannot be opened
    }
    fin >> Rows >> Cols; // Read the number of rows and columns from the file
    Mat.resize(Rows, vector<double>(Cols)); // Resize the matrix to match the dimensions read from the file
    for (int i = 0; i < Rows; i++) { // Loop over each row
        for (int j = 0; j < Cols - 1; j++) { // Loop over each column except the last one
            fin >> Mat[i][j]; // Read each element from the file
        }
    }
    fin.close(); // Close the file

    // Reading R matrix (constants)
    fin.open(fileName_R); // Open the file containing the R matrix
    if (!fin.is_open()) { // Check if the file was successfully opened
        throw runtime_error("Error opening file: " + fileName_R); // Throw an error if the file cannot be opened
    }
    for (int i = 0; i < Rows; i++) { // Loop over each row
        fin >> Mat[i][Cols - 1]; // Read the last column element from the file
    }
    fin.close(); // Close the file
}

// Function to print the matrix
void Matrix::PrintMatrix() const {
    for (int i = 0; i < Mat.size(); i++) { // Loop over each row
        for (int j = 0; j < Mat[i].size(); j++) { // Loop over each column in the current row
            cout << Mat[i][j] << " "; // Print each element followed by a space
        }
        cout << endl; // New line for each row
    }
}

// Function to get the lower triangular matrix element at (rowIndex, colIndex)
double Matrix::GetLowerTriangular(const Matrix& L, const Matrix& U, int rowIndex, int colIndex) const {
    if (rowIndex < colIndex) return 0; // Lower triangular element is zero if rowIndex < colIndex

    double sum = 0;
    for (int k = 0; k < colIndex; k++) { // Sum up the products of corresponding elements in row of L and column of U up to colIndex
        sum += L.Mat[rowIndex][k] * U.Mat[k][colIndex];
    }
    return Mat[rowIndex][colIndex] - sum; // Subtract the sum from the original matrix element to get the lower triangular element
}

// Function to get the upper triangular matrix element at (rowIndex, colIndex)
double Matrix::GetUpperTriangular(const Matrix& L, const Matrix& U, int rowIndex, int colIndex) const {
    if (rowIndex > colIndex) return 0; // Upper triangular element is zero if rowIndex > colIndex

    if (rowIndex == colIndex) return 1; // Diagonal of upper triangular matrix is 1

    double sum = 0;
    for (int k = 0; k < rowIndex; k++) { // Sum up the products of corresponding elements in row of L and column of U up to rowIndex
        sum += L.Mat[rowIndex][k] * U.Mat[k][colIndex];
    }
    return (Mat[rowIndex][colIndex] - sum) / L.Mat[rowIndex][rowIndex]; // Calculate and return the upper triangular element
}

// Function to perform LU Decomposition
void Matrix::LUDecomposition() const {
    Matrix L(Rows, Cols); // Initialize lower triangular matrix L
    Matrix U(Rows, Cols); // Initialize upper triangular matrix U

    for (int rowIndex = 0; rowIndex < Rows; rowIndex++) { // Loop over each row
        for (int colIndex = 0; colIndex < Cols; colIndex++) { // Loop over each column
            if (colIndex >= rowIndex) { // If we are in or above the diagonal
                U.Mat[rowIndex][colIndex] = GetUpperTriangular(L, U, rowIndex, colIndex); // Calculate the upper triangular element
            }
            if (colIndex <= rowIndex) { // If we are in or below the diagonal
                L.Mat[rowIndex][colIndex] = GetLowerTriangular(L, U, rowIndex, colIndex); // Calculate the lower triangular element
            }
        }
    }

    cout << "Lower Triangular Matrix:" << endl; // Print a message for lower triangular matrix
    L.PrintMatrix(); // Print the lower triangular matrix
    cout << "Upper Triangular Matrix:" << endl; // Print a message for upper triangular matrix
    U.PrintMatrix(); // Print the upper triangular matrix
}
