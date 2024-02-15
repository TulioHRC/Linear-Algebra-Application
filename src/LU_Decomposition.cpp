#include "LU_Decomposition.hpp"

std::pair<Matrix *, Matrix *> getLUfromDecomposition(Matrix A) // A = LU
{
    // Error Handler (0 on pivotal lines)

    std::vector<std::vector<long double>> uTable = A.getTable();

    std::vector<long double> zeroRows(A.getColumns(), 0);
    std::vector<std::vector<long double>> *lTable = new std::vector<std::vector<long double>>(A.getRows(), zeroRows);

    for (int row = 0; row < A.getRows(); row++)
    {
        (*lTable)[row][row] = 1;
        for (int downRow = row + 1; downRow < A.getRows(); downRow++)
        {
            long double multiplier = uTable[downRow][row] / uTable[row][row];
            (*lTable)[downRow][row] = multiplier;
            uTable[downRow][row] = 0;
        }
    }

    Matrix *L = new Matrix(A.getRows(), A.getColumns(), *lTable);
    Matrix *U = new Matrix(A.getRows(), A.getColumns(), uTable);

    std::pair<Matrix *, Matrix *> result;
    result.first = L;
    result.second = U;

    return result;
}