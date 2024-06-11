#ifndef GAUSSIAN_HPP
#define GAUSSIAN_HPP

#include <vector>
#include <string>

class GaussianElimination {
public:
    GaussianElimination(const std::string& fileName_L, const std::string& fileName_R);
    void performGaussianElimination();
    void backSubstitution();
    void printMatrix() const;
    void printSolution() const;

private:
    std::vector<std::vector<double>> mat;
    std::vector<double> solution;
    int rows;
    int cols;

    void readMatrix(const std::string& fileName_L, const std::string& fileName_R);
};

#endif // GAUSSIAN_HPP
