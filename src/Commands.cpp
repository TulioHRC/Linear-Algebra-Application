#include "Commands.hpp"
#include "MemoryFunctions.hpp"

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

void saveCommand(std::vector<Matrix *> matrices)
{
    loadProgramTerminal("Saving matrices");

    saveMatricesOnTxtFile(matrices);

    std::cout << "Matrices saved" << std::endl;
}

std::vector<Matrix *> getMatricesMemoryCommand()
{
    return readMatricesOnTxtFile();
}

void operationsCommand(std::vector<Matrix *> &matrices)
{
    std::cout << "\n\tOperations mode" << std::endl;
    std::vector<std::string> operationsList = {"plus", "subtraction", "product"};
    std::string operationSelected = operationsList[selectListItemTerminal(operationsList)];
    Matrix itemSelected1 = getMatrixSaved(matrices, false);
    Matrix itemSelected2 = getMatrixSaved(matrices, (operationSelected == "product") ? true : false, itemSelected1.getRows());
    Matrix *result;

    if (operationSelected == "plus")
        result = new Matrix(itemSelected1 + itemSelected2);
    if (operationSelected == "subtraction")
        result = new Matrix(itemSelected1 - itemSelected2);
    if (operationSelected == "product")
        result = new Matrix(itemSelected1 * itemSelected2);

    std::cout << std::endl;
    matrices.push_back(result);
    result->showMatrix();
}

void viewOptionsCommand()
{
    std::cout << "\n\tLinear Algebra Application\n " << std::endl;

    std::vector<std::string> options = {
        "c -> Create a matrix",
        "v -> View saved matrices",
        "s -> Save matrices in the app memory",
        "o -> Operations mode of matrices",
        "e -> exit"};

    for (std::string option : options)
        std::cout << option << std::endl;

    std::cout << std::endl;
}

void exitCommand()
{
    loadProgramTerminal("Finishing Program");
    exit(0);
}