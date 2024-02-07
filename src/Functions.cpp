#include <cstdlib>
#include "Functions.hpp"

std::vector<std::vector<long long>> *getTable()
{
    std::cout << "Creating your own matrix..." << std::endl;

    int rows, columns;
    std::cout << "Type the number of rows: ";
    std::cin >> rows;

    std::cout << "Type the number of columns: ";
    std::cin >> columns;

    std::vector<std::vector<long long>> *table = new std::vector<std::vector<long long>>(rows);

    for (int i = 0; i < rows; i++)
        (*table)[i].resize(columns);

    for (int r = 0; r < rows; r++)
    {
        std::cout << "Row " << r + 1 << ":" << std::endl;
        for (int c = 0; c < columns; c++)
            std::cin >> (*table)[r][c];
    }

    std::cout << "\nMatrix created." << std::endl;

    return table;
}