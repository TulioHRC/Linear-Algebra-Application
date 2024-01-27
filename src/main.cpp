#include "Matrix.hpp"
#include "Functions.hpp"
#include <string.h>
#include <iostream>
#include <limits>

void commandSwitch(std::string command, std::vector<Matrix *> &matrices)
{
    if (command == "c" || command == "create")
    {
        std::vector<std::vector<long long>> *table = getTable();
        Matrix *matrix = new Matrix((*table).size(), (*table)[0].size(), *table);
        matrices.push_back(matrix);

        std::cin.get();
    }
    if (command == "s" || command == "show")
    {
        std::cout << "\n\tSaved Matrices:" << std::endl;
        for (size_t i = 0; i < matrices.size(); i++)
        {
            std::cout << "\n(" << i + 1 << ")" << std::endl;
            matrices[i]->showMatrix();
        }
    }
    if (command == "e" || command == "exit")
    {
        std::cout << "Finishing program..." << std::endl;
        exit(0);
    }
}

int main()
{
    std::cout << "Starting...\n"
              << std::endl;

    std::vector<Matrix *> matrices;

    std::string command;
    std::cin >> command;

    while (command != "q" && command != "quit")
    {
        std::cin.ignore();
        commandSwitch(command, matrices);

        std::cout << "\nPress enter to continue..." << std::endl;
        std::cin.ignore();

        clearTerminal();
        std::cin >> command;
    }

    std::cout << "\nFinishing the application..." << std::endl;

    for (Matrix *matrix : matrices)
        delete matrix;

    return 0;
}