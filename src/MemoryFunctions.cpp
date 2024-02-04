#include "MemoryFunctions.hpp"

// memory.txt format -> cell1,cell2,cell3,;cell4,cell5,cell6,; (it's a 2x3 matrix)
void saveMatricesOnTxtFile(std::vector<Matrix *> matrices)
{
    std::ofstream outputMemoryTxtFile("./data/memory.txt");

    if (!outputMemoryTxtFile.is_open())
    {
        std::cerr << "Error while opening memory file." << std::endl;
        return;
    }

    for (Matrix *matrix : matrices)
    {
        std::vector<std::vector<long long>> table = matrix->getTable();
        for (auto row : table)
        {
            for (long long cell : row)
            {
                std::cout << cell << ",";
                outputMemoryTxtFile << cell << ",";
            }
            outputMemoryTxtFile << ";";
        }
        outputMemoryTxtFile << std::endl;
    }

    outputMemoryTxtFile.close();
}

std::vector<Matrix *> readMatricesOnTxtFile()
{
    std::ifstream inputMemoryTxtFile("./data/memory.txt");
    std::vector<Matrix *> matrices;

    if (!inputMemoryTxtFile.is_open())
    {
        std::cout << "There's no memory file at your application." << std::endl;
        return matrices;
    }

    std::vector<std::string> matricesTxtFormatVector;
    std::string matrixLine;

    while (std::getline(inputMemoryTxtFile, matrixLine))
        matricesTxtFormatVector.push_back(matrixLine);

    for (auto matrixText : matricesTxtFormatVector)
    {
        std::vector<std::vector<long long>> *table = nullptr;
        std::vector<long long> row;
        std::string numberText;
        numberText = "";

        for (char letter : matrixText)
        {
            switch (letter)
            {
            case ';':
                table->push_back(row);
                row.clear();

                break;

            case ',':
                row.push_back(std::stoll(numberText));
                numberText.clear();

                break;

            default:
                numberText.push_back(letter);

                break;
            }
        }

        Matrix *matrixPtr = nullptr;
        *matrixPtr = Matrix(static_cast<int>(table->size()), static_cast<int>(table[0].size()), *table);
        matrices.push_back(matrixPtr);

        delete table;
    }

    inputMemoryTxtFile.close();

    return matrices;
}