#include "Commands.hpp"

void createCommand(std::vector<Matrix *> &matrices)
{
    std::vector<std::vector<long long>> *table = getTable();
    Matrix *matrix = new Matrix((*table).size(), (*table)[0].size(), *table);
    matrices.push_back(matrix);

    std::cin.get();
}

void viewCommand(std::vector<Matrix *> matrices)
{
    std::cout << "\n\tSaved Matrices:" << std::endl;
    for (size_t i = 0; i < matrices.size(); i++)
    {
        std::cout << "\n(" << i + 1 << ")" << std::endl;
        matrices[i]->showMatrix();
    }
}

void operationsCommand(std::vector<Matrix *> &matrices)
{
    std::cout << "\n\tOperations mode" << std::endl;
    std::vector<std::string> operationsList = {"plus", "subtraction", "product"};
    std::string operationSelected = operationsList[selectListItemTerminal(operationsList)];
}

void exitCommand()
{
    loadProgramTerminal("Finishing Program");
    exit(0);
}