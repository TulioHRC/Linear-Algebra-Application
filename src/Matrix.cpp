#include "Matrix.hpp"

Matrix::Matrix(int rows, int columns, std::vector<std::vector<long long>> table) : _rows(rows), _columns(columns)
{
    std::vector<std::vector<long long>> *tablePtr = new std::vector<std::vector<long long>>(table);
    this->_table = tablePtr;
}

Matrix::Matrix(const Matrix &otherTable) : _rows(otherTable._rows), _columns(otherTable._columns)
{
    std::vector<std::vector<long long>> *tableCopy = new std::vector<std::vector<long long>>(otherTable._rows);

    for (int i = 0; i < otherTable._rows; i++)
        (*tableCopy)[i].resize(otherTable._columns);

    for (int r = 0; r < this->_rows; r++)
        for (int c = 0; c < this->_columns; c++)
            (*tableCopy)[r][c] = (*otherTable._table)[r][c];

    _table = tableCopy;
}

Matrix::Matrix(int dimension) : _rows(dimension), _columns(dimension)
{
    std::vector<long long> zeroRows(dimension, 0);
    std::vector<std::vector<long long>> *table = new std::vector<std::vector<long long>>(dimension, zeroRows);

    for (int i = 0; i < dimension; i++)
        (*table)[i][i] = 1;

    _table = table;
}

Matrix::~Matrix() { delete _table; }

Matrix Matrix::transpose()
{
    std::vector<std::vector<long long>> *tTable = new std::vector<std::vector<long long>>(this->_columns);

    for (int i = 0; i < this->_rows; i++)
        (*tTable)[i].resize(this->_columns);

    for (int r = 0; r < this->_rows; r++)
        for (int c = 0; c < this->_columns; c++)
            (*tTable)[c][r] = (*_table)[r][c];

    Matrix *tMatrix = new Matrix(this->_columns, this->_rows, *tTable);

    delete tTable;

    return *tMatrix;
}

void Matrix::showMatrix()
{
    for (int r = 0; r < this->_rows; r++)
    {
        std::cout << "[ ";

        for (int c = 0; c < this->_columns; c++)
            std::cout << (*this->_table)[r][c] << " ";

        std::cout << "]" << std::endl;
    }
}

int Matrix::getRows()
{
    return this->_rows;
}

int Matrix::getColumns()
{
    return this->_columns;
}

std::vector<std::vector<long long>> Matrix::getTable()
{
    return *_table;
}

// Operator Overload

Matrix &Matrix::operator=(const Matrix &otherTable)
{
    *this->_table = *otherTable._table;
    this->_rows = otherTable._rows;
    this->_columns = otherTable._columns;
    return *this;
}

Matrix Matrix::operator+(const Matrix &otherTable)
{
    std::vector<long long> zeroRows(otherTable._columns, 0);
    std::vector<std::vector<long long>> resTable(this->_rows, zeroRows);

    for (int r = 0; r < this->_rows; r++)
        for (int c = 0; c < this->_columns; c++)
            resTable[r][c] = (*_table)[r][c] + (*otherTable._table)[r][c];
    return Matrix(this->_rows, otherTable._columns, resTable);
}

Matrix Matrix::operator-(const Matrix &otherTable)
{
    std::vector<long long> zeroRows(otherTable._columns, 0);
    std::vector<std::vector<long long>> resTable(this->_rows, zeroRows);

    for (int r = 0; r < this->_rows; r++)
        for (int c = 0; c < this->_columns; c++)
            resTable[r][c] = (*_table)[r][c] - (*otherTable._table)[r][c];
    return Matrix(this->_rows, otherTable._columns, resTable);
}

Matrix Matrix::operator*(const Matrix &otherTable)
{
    // Error handling (not respecting the n x m . m x p)

    std::vector<std::vector<long long>> table(this->_rows);
    for (int i = 0; i < this->_rows; i++)
        table[i].resize(otherTable._columns);

    for (int r = 0; r < this->_rows; r++)
        for (int c = 0; c < otherTable._columns; c++)
        {
            table[r][c] = 0;
            for (int i = 0; i < this->_rows; i++)
                table[r][c] += (*this->_table)[r][i] * (*otherTable._table)[i][c];
        }

    return Matrix(this->_rows, otherTable._columns, table);
}

// Operator Overload for scalar numbers

Matrix Matrix::operator+(long long scalarNum)
{
    // Error Handling (for not squares matrix)
    Matrix identity(this->_rows);
    return *this + identity * scalarNum;
}

Matrix Matrix::operator-(long long scalarNum)
{
    // Error Handling (for not squares matrix)
    Matrix identity(this->_rows);
    return *this - identity * scalarNum;
}

Matrix Matrix::operator*(long long scalarNum)
{
    std::vector<long long> zeroRows(this->_columns, 0);
    std::vector<std::vector<long long>> resTable(this->_rows, zeroRows);

    for (int r = 0; r < this->_rows; r++)
        for (int c = 0; c < this->_columns; c++)
            resTable[r][c] = (*this->_table)[r][c] * scalarNum;

    return Matrix(this->_rows, this->_columns, resTable);
}