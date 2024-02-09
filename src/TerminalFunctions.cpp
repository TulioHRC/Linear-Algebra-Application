#include "TerminalFunctions.hpp"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <sstream>

void clearTerminal()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void loadProgramTerminal(std::string message)
{
    clearTerminal();
    std::cout << message;

    for (int loop = 0; loop < 3; loop++)
    {
        for (int i = 0; i < 3; i++)
        {
            std::cout << "." << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }

        std::cout << "\b\b\b   \b\b\b" << std::flush; // Clear points
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    clearTerminal();
}

void showMenu(std::vector<std::string> options, size_t selected)
{
    clearTerminal();

    for (size_t i = 0; i < options.size(); ++i)
    {
        if (i == selected)
            std::cout << "-> " << options[i] << std::endl;
        else
            std::cout << "   " << options[i] << std::endl;
    }
}

void showSingleOption(std::string option)
{
    clearTerminal();

    std::cout << option << std::endl;
}

int selectListMatrixTerminal(std::vector<Matrix *> matrices)
{
    std::vector<std::string> stringMatrices;
    int index = 0;
    for (Matrix *matrix : matrices)
    {
        std::string stringMatrix = "(" + std::to_string(index + 1) + ")\n";

        // Get matrix text
        std::stringstream ss;
        std::streambuf *originalCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(ss.rdbuf()); // Redirecting cout
        matrix->showMatrix();
        std::cout.rdbuf(originalCoutStreamBuf); // Restore cout
        stringMatrix += ss.str();

        stringMatrices.push_back(stringMatrix);
        index++;
    }

    return selectListItemTerminal(stringMatrices, false);
}

int selectListItemTerminal(std::vector<std::string> options, bool showAllOptions)
{
    size_t selected = 0;
    char key;

    do
    {
        if (showAllOptions)
            showMenu(options, selected);
        else
            showSingleOption(options[selected]);

        key = _getch();

        switch (key)
        {
        case 72:
            selected = (selected == 0) ? 0 : selected - 1;
            break;
        case 80:
            selected = (selected == options.size() - 1) ? selected : selected + 1;
        }
    } while (key != 13); // 13 is Enter

    return selected;
}