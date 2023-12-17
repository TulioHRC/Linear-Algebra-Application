#include "Matrice.hpp"

Matrice::Matrice(int rows, int columns, std::vector<std::vector<long long>> table) : _rows(rows), _columns(columns) {
    *_table = table;
};

Matrice::~Matrice(){ delete _table; }

Matrice Matrice::transpose(){
    std::vector<std::vector<long long>> tMatrice(this->_columns);

    for(int i = 0; i<this->_columns; i++)
        tMatrice[i].resize(this->_rows);

    for(int r = 0; r<this->_rows; r++)
        for(int c = 0; c<this->_columns; c++)
            tMatrice[c][r] = this->_table[r][c];
} 

void Matrice::showMatrice(){
    for(int r = 0; r<this->_rows; r++){
        std::cout << "[ ";

        for(int c = 0; c<this->_columns; c++) 
            std::cout << this->_table[r][c] << " ";
        
        std::cout << "]" << std::endl;
    }
}