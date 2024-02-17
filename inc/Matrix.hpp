#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

class Matrix
{
private:
    int _rows, _columns;
    std::vector<std::vector<long double>> *_table = nullptr; // It's basically the fundamental structure of a Matrix
public:
    Matrix(int rows, int columns, std::vector<std::vector<long double>> table);
    Matrix(const Matrix &); // Deep Copy
    Matrix(int dimension);  // Identity matrix (n x n)
    ~Matrix();

    Matrix transpose();
    void showMatrix();
    int getRows();
    int getColumns();
    std::vector<std::vector<long double>> getTable();

    Matrix &operator=(const Matrix &);
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &); // Matrix product

    Matrix operator+(long double scalarNum);
    Matrix operator-(long double scalarNum);
    Matrix operator*(long double scalarNum); // Matrix product with scalar number
};

#endif