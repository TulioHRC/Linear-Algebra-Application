#ifndef COMMANDS_H
#define COMMANDS_H

#include "Matrix.hpp"
#include "Functions.hpp"
#include "TerminalFunctions.hpp"

void createCommand(std::vector<Matrix *> &);
void viewCommand(std::vector<Matrix *>);
void saveCommand(std::vector<Matrix *>);
std::vector<Matrix *> getMatricesMemoryCommand();
void operationsCommand(std::vector<Matrix *> &);
void viewOptionsCommand();
void exitCommand();

#endif