#ifndef MEMORY_FUNCTIONS_H
#define MEMORY_FUNCTIONS_H

#include "Matrix.hpp"

void saveMatricesOnTxtFile(std::vector<Matrix *>);
std::vector<Matrix *> readMatricesOnTxtFile();

#endif