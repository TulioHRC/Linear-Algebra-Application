#include "Matrix.hpp"

int main(){
    std::cout << "Starting...\n" << std::endl;

    Matrix identity(3);

    identity = identity + 2;

    identity.showMatrix();

    Matrix transposeIdentity(identity.transpose());

    transposeIdentity.showMatrix();

    return 0;
}