#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Basic functions used in the application

#include "Matrix.hpp"
#include "TerminalFunctions.hpp"

std::vector<std::vector<long long>> *getTable(); // Return a matrix given in the command line
Matrix getMatrixSaved(std::vector<Matrix *>, bool canBeNumber, int rowsPresetWhenSecondMatrix = 0);

#endif