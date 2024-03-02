#ifndef DECOMPOSITIONS_H
#define DECOMPOSITIONS_H

#include "Matrix.hpp"
#include <cmath>

struct ThreeMatrices {
    Matrix* first;
    Matrix* second;
    Matrix* third;
};

std::pair<Matrix*, Matrix*> getLUfromDecomposition(Matrix);
ThreeMatrices getPAequalsLUfromDecomposition(Matrix);
std::pair<Matrix*, Matrix*> getQRclassicFromDecomposition(Matrix);

#endif