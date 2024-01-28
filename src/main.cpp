#include "Commands.hpp"
#include <iostream>

void commandSwitch(char command, std::vector<Matrix *> &matrices)
{
    switch (command)
    {
    case 'c':
        createCommand(matrices);
        break;

    case 'v':
        viewCommand(matrices);
        break;

    case 'o':
        operationsCommand(matrices);
        break;

    case 'e':
        exitCommand();
        break;
    }
}

int main()
{
    loadProgramTerminal("Starting program");
    viewOptionsCommand();

    std::vector<Matrix *> matrices;

    char command;
    std::cin.get(command);

    while (true)
    {
        std::cin.ignore();
        commandSwitch(command, matrices);

        std::cout << "\nCommand executed. Press enter to continue..." << std::endl;
        std::cin.ignore();

        clearTerminal();
        viewOptionsCommand();
        std::cin.get(command);
    }

    for (Matrix *matrix : matrices)
        delete matrix;

    return 0;
}