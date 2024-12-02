#include <iostream>
#include "Pair.cpp"
#include "adjacency_matrix.cpp"

int main()
{
    std::cout << "Alright!" << std::endl;
    AdjMatrix mtr(3);
    std::ifstream f("adjacency_matrix.txt");
    mtr.write(f);
    std::cout << mtr;
    std::cout << std::endl;
    return 0;
}