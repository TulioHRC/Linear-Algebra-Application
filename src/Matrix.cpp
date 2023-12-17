#include "Matrix.hpp"

Matrix::Matrix(int rows, int columns, std::vector<std::vector<long long>> table) : _rows(rows), _columns(columns) {
    *_table = table;
}

Matrix::Matrix(const Matrix& otherTable) : _rows(otherTable._rows), _columns(otherTable._columns) {
    std::vector<std::vector<long long>>* tableCopy = new std::vector<std::vector<long long>>(otherTable._rows);

    for(int i = 0; i<otherTable._rows; i++)
        (*tableCopy)[i].resize(otherTable._columns);

    for(int r = 0; r<this->_rows; r++)
        for(int c = 0; c<this->_columns; c++)
            (*tableCopy)[r][c] = (*otherTable._table)[r][c];

    _table = tableCopy;
}

Matrix::Matrix(int dimension) : _rows(dimension), _columns(dimension) {
    std::vector<long long> zeroRows(dimension, 0);
    std::vector<std::vector<long long>>* table = new std::vector<std::vector<long long>>(dimension, zeroRows);

    for(int i = 0; i<dimension; i++)
        (*table)[i][i] = 1;
    
    _table = table;
}

Matrix::~Matrix(){ delete _table; }

Matrix Matrix::transpose(){
    std::vector<std::vector<long long>> tTable(this->_columns);

    for(int i = 0; i<this->_columns; i++)
        tTable[i].resize(this->_rows);

    for(int r = 0; r<this->_rows; r++)
        for(int c = 0; c<this->_columns; c++)
            tTable[c][r] = (*_table)[r][c];
    
    Matrix tMatrix(this->_columns, this->_rows, tTable);

    return tMatrix;
} 

void Matrix::showMatrix(){
    for(int r = 0; r<this->_rows; r++){
        std::cout << "[ ";

        for(int c = 0; c<this->_columns; c++) 
            std::cout << (*this->_table)[r][c] << " ";
        
        std::cout << "]" << std::endl;
    }
}

// Operator Overload

Matrix& Matrix::operator=(const Matrix& otherTable){
    *this->_table = *otherTable._table;
    this->_rows = otherTable._rows;
    this->_columns = otherTable._columns;
    return *this;
}

Matrix Matrix::operator+(const Matrix& otherTable){
    for(int r = 0; r<this->_rows; r++)
        for(int c = 0; c<this->_columns; c++)
            (*_table)[r][c] += (*otherTable._table)[r][c];
    return *this;
}

Matrix Matrix::operator-(const Matrix& otherTable){
    for(int r = 0; r<this->_rows; r++)
        for(int c = 0; c<this->_columns; c++)
            (*_table)[r][c] -= (*otherTable._table)[r][c];
    return *this;
}

Matrix Matrix::operator*(const Matrix& otherTable){
    // Error handling (not respecting the n x m . m x p)

    std::vector<std::vector<long long>> table(this->_rows);
    for(int i = 0; i<this->_rows; i++)
        table[i].resize(otherTable._columns);
    
    for(int r = 0; r<this->_rows; r++)
        for(int c = 0; c<otherTable._columns; c++){
            table[r][c] = 0; 
            for(int i = 0; i<this->_rows; i++)
                table[r][c] += (*this->_table)[r][i] * (*otherTable._table)[i][c];
        }

    Matrix newMatrix(this->_rows, otherTable._columns, table);

    return newMatrix;
}

// Operator Overload for scalar numbers

Matrix Matrix::operator+(long long scalarNum){
    // Error Handling (for not squares matrix)

    Matrix identity(this->_rows);
    *this = *this + identity*scalarNum;

    return *this;
}

Matrix Matrix::operator-(long long scalarNum){
    // Error Handling (for not squares matrix)

    Matrix identity(this->_rows);
    *this = *this - identity*scalarNum;

    return *this;
}


Matrix Matrix::operator*(long long scalarNum){
    for(int r = 0; r<this->_rows; r++)
        for(int c = 0; c<this->_columns; c++)
            (*this->_table)[r][c] *= scalarNum;
    
    return *this;
}