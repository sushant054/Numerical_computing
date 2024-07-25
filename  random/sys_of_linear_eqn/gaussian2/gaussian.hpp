#ifndef GAUSSIAN_HPP
#define GAUSSIAN_HPP

#include <vector>

void printMatrix(std::vector<std::vector<double>>& mat);
void gaussianElimination(std::vector<std::vector<double>>& mat);
void backSubstitution(std::vector<std::vector<double>>& mat);

#endif // GAUSSIAN_HPP
