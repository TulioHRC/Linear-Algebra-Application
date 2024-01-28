#include "TerminalFunctions.hpp"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

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

int selectListItemTerminal(std::vector<std::string> options)
{
    size_t selected = 0;
    char key;

    do
    {
        showMenu(options, selected);
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