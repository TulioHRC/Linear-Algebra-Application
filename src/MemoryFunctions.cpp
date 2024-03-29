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
        std::vector<std::vector<long double>> table = matrix->getTable();
        for (auto row : table)
        {
            for (long double cell : row)
                outputMemoryTxtFile << cell << ",";
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
        int rows = 0;
        int columns = 0;
        std::vector<std::vector<long double>> table;
        std::vector<long double> row;
        std::string numberText;
        numberText = "";

        for (char letter : matrixText)
        {
            switch (letter)
            {
            case ';':
                table.push_back(row);
                rows++;
                row.clear();

                break;

            case ',':
                row.push_back(std::stoll(numberText));
                if (rows == 0)
                    columns++;
                numberText.clear();

                break;

            default:
                numberText.push_back(letter);

                break;
            }
        }

        Matrix *matrixPtr = nullptr;
        matrixPtr = new Matrix(rows, columns, table);
        matrices.push_back(matrixPtr);
    }

    inputMemoryTxtFile.close();

    return matrices;
}