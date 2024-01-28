#ifndef TERMINAL_H
#define TERMINAL_H

#include "Matrix.hpp"

void clearTerminal();
void loadProgramTerminal(std::string);
int selectListItemTerminal(std::vector<std::string>); // Returns the index of the selected item

#endif