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
    std::string operationSelected = operationsList[selectListItemTerminal(operationsList, true)];
    Matrix *result;

    Matrix itemSelected1 = getMatrixSaved(matrices);
    std::cout << "\nFirst matrix selected.";
    if (operationSelected == "product")
        std::cout << " Select between a scalar number or other matrix.";
    std::cout << "\nPress enter to select the second...";
    std::cin.ignore();

    bool isNumber = false;
    Matrix *itemSelected2 = nullptr;

    if (operationSelected == "product")
        isNumber = (selectListItemTerminal(std::vector<std::string>{"Number", "Matrix"}, true) == 0) ? true : false;
    if (isNumber)
    {
        long long number = getNumber();
        itemSelected1 = itemSelected1 * number;
        result = new Matrix(itemSelected1);
    }
    else
        itemSelected2 = new Matrix(getMatrixSaved(matrices));
    std::cout << "\nSecond item selected.\nPress enter to see the result..." << std::endl;
    std::cin.ignore();
    clearTerminal();

    try
    {
        if (isNumber == false)
        {
            if (operationSelected == "plus")
                result = new Matrix(itemSelected1 + *itemSelected2);
            if (operationSelected == "subtraction")
                result = new Matrix(itemSelected1 - *itemSelected2);
            if (operationSelected == "product")
                result = new Matrix(itemSelected1 * *itemSelected2);
        }
        delete itemSelected2;

        std::cout << "Result:" << std::endl;
        matrices.push_back(result);
        result->showMatrix();
        std::cout << "\nMatrice saved, if you want to use this in the future, save the matrices in the app memory." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\nAn error occured!!!" << std::endl;
        std::cerr << e.what() << std::endl;
    }
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