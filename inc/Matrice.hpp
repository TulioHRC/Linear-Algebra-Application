#ifndef MATRICE_H
#define MATRICE_H

#include <vector>

class Matrice 
{
    private:
        int _rows, _columns;
        std::vector<std::vector<long long>>* _table; // It's basically the fundamental structure of a matrice
    public:
        Matrice(int rows, int columns, std::vector<std::vector<long long>> table);
        Matrice(const Matrice&);
        ~Matrice();

        Matrice transpose();
        void showMatrice();

        Matrice& operator=(const Matrice&);
        Matrice operator+(const Matrice&);
        Matrice operator-(const Matrice&);
        Matrice operator*(const Matrice&);
};

#endif