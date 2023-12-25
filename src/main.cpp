#include "Matrix.hpp"
#include "Functions.hpp"
#include <string.h>

int main(){
    std::cout << "Starting...\n" << std::endl;

    std::vector<Matrix*> matrices;

    std::string command;
    std::cin >> command;
 
    while(command != "q" && command != "quit") {
        if(command == "c" or command == "create"){ // Create matrix
            std::vector<std::vector<long long>>* table = getTable();
            Matrix* matrix = new Matrix((*table).size(), (*table)[0].size(), *table);
            matrices.push_back(matrix);
        }

        std::cin >> command;
    }

    std::cout << "\nFinishing the application..." << std::endl;

    for(Matrix* matrix : matrices)
        delete matrix;

    return 0;
}