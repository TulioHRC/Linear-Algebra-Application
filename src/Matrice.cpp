#include "Matrice.hpp"

Matrice::Matrice(int rows, int columns, std::vector<std::vector<long long>> table) : _rows(rows), _columns(columns) {
    *_table = table;
};

Matrice::~Matrice(){ delete _table; }

Matrice Matrice::transpose(){
    std::vector<std::vector<long long>> tMatrice(this->_columns);

    for(int i = 0; i<this->_columns; i++)
        tMatrice[i].resize(this->_rows);
} 