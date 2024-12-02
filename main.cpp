#include <iostream>
#include "Pair.cpp"


int main()
{
    std::cout << "Alright!" << std::endl;
    Pair<int, int> p(1, 2);
    std::cout << p << std::endl;
    return 0;
}