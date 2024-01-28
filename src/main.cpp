#include "Commands.hpp"
#include <iostream>

void commandSwitch(std::string command, std::vector<Matrix *> &matrices)
{
    if (command == "c" || command == "create")
    {
        createCommand(matrices);
    }
    if (command == "v" || command == "view")
    {
        viewCommand(matrices);
    }
    if (command == "o" || command == "operation")
    {
        operationsCommand(matrices);
    }
    if (command == "e" || command == "exit")
    {
        exitCommand();
    }
}

int main()
{
    loadProgramTerminal("Starting program");

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
        // viewOptionsCommand();
        std::cin >> command;
    }

    std::cout << "\nFinishing the application..." << std::endl;

    for (Matrix *matrix : matrices)
        delete matrix;

    return 0;
}