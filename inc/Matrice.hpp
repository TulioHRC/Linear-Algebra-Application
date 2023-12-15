#ifndef MATRICE_H
#define MATRICE_H

#include <vector>

/*
Only basics operations of matrices
- Sum, Subtration, Multiplication
- Transposition
*/
class Matrice 
{
    private:
        int _rows, _columns;
        std::vector<std::vector<long long>>* _table; // It's basically the fundamental structure of a matrice
    public:
        Matrice(int rows, int columns, std::vector<std::vector<long long>> table);
        ~Matrice();

        Matrice* transpose();

        Matrice& operator=(const Matrice&);
        Matrice& operator+(const Matrice&);
        Matrice& operator-(const Matrice&);
        Matrice& operator*(const Matrice&);
};

#endif