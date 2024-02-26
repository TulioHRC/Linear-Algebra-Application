#include "Decompositions.hpp"

void moveRowsOfTable(std::vector<std::vector<long double>> &uTable, int from, int to)
{
    std::vector<std::vector<long double>> copyTable = uTable;
    int size = uTable.size();

    for (int row = 0; row < size; row++)
    {
        if (row == from)
            uTable[row] = copyTable[to];
        else if (row == to)
            uTable[row] = copyTable[from];
    }
}

std::pair<Matrix *, Matrix *> getLUfromDecomposition(Matrix A) // A = LU
{
    // Error Handler (0 on pivotal lines)

    std::vector<std::vector<long double>> uTable = A.getTable();

    std::vector<long double> zeroRows(A.getRows(), 0);
    std::vector<std::vector<long double>> *lTable = new std::vector<std::vector<long double>>(A.getRows(), zeroRows);

    for (int row = 0; row < A.getRows(); row++)
    {
        (*lTable)[row][row] = 1;
        for (int downRow = row + 1; downRow < A.getRows(); downRow++)
        {
            long double multiplier = uTable[downRow][row] / uTable[row][row];
            (*lTable)[downRow][row] = multiplier;
            uTable[downRow][row] = 0;
            if (row < A.getRows() - 1)
                for (int col = row + 1; col < A.getColumns(); col++)
                {
                    uTable[downRow][col] -= uTable[row][col] * multiplier;
                }
        }
    }

    Matrix *L = new Matrix(A.getRows(), A.getRows(), *lTable);
    Matrix *U = new Matrix(A.getRows(), A.getColumns(), uTable);

    delete lTable;

    std::pair<Matrix *, Matrix *> result;
    result.first = L;
    result.second = U;

    return result;
}

ThreeMatrices getPAequalsLUfromDecomposition(Matrix A)
{
    Matrix *P = new Matrix(A.getRows());
    std::vector<int> orderOfP;
    for (int row = 0; row < A.getRows(); row++)
        orderOfP.push_back(row);

    std::vector<std::vector<long double>> uTable = A.getTable();
    std::vector<std::vector<long double>> multipliersVectorByRow(A.getRows());

    std::vector<long double> zeroRows(A.getRows(), 0);
    std::vector<std::vector<long double>> *lTable = new std::vector<std::vector<long double>>(A.getRows(), zeroRows);

    for (int row = 0; row < A.getRows(); row++)
    {
        int pivotRow = row;
        for (int downRow = row + 1; downRow < A.getRows(); downRow++)
        {
            if (abs(uTable[downRow][row]) > abs(uTable[pivotRow][row]))
                pivotRow = downRow;
        }

        P->moveRowsFromTo(row, pivotRow);
        std::vector<int> lastOrderOfP = orderOfP;
        orderOfP[row] = lastOrderOfP[pivotRow];
        orderOfP[pivotRow] = lastOrderOfP[row];
        moveRowsOfTable(uTable, row, pivotRow);

        for (int downRow = row + 1; downRow < A.getRows(); downRow++)
        {
            long double multiplier = uTable[downRow][row] / uTable[row][row];
            multipliersVectorByRow[orderOfP[downRow]].push_back(multiplier);
            uTable[downRow][row] = 0;
            if (row < A.getRows() - 1)
                for (int col = row + 1; col < A.getColumns(); col++)
                {
                    uTable[downRow][col] -= uTable[row][col] * multiplier;
                }
        }
    }

    for (int row = 0; row < A.getRows(); row++)
    {
        (*lTable)[row][row] = 1;
        for (int column = 0; column < row; column++)
        {
            (*lTable)[row][column] = multipliersVectorByRow[orderOfP[row]][column];
        }
    }

    Matrix *L = new Matrix(A.getRows(), A.getRows(), *lTable);
    Matrix *U = new Matrix(A.getRows(), A.getColumns(), uTable);

    delete lTable;

    ThreeMatrices result;
    result.first = P;
    result.second = L;
    result.third = U;

    return result;
}