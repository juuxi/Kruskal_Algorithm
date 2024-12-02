#include <iostream>
#include "Timsort.cpp"
#include "adjacency_matrix.cpp"

int main()
{
    std::cout << "Alright!" << std::endl;
    AdjMatrix mtr(3);
    std::ifstream f("adjacency_matrix.txt");
    mtr.write(f);
    std::cout << mtr;
    std::cout << std::endl;
    int minrun = count_minrun(3);
    Pair<int, std::string> p1(3, "a b");
    Pair<int, std::string> p2(1, "a c");
    Pair<int, std::string> p3(2, "b c");
    Vector<Pair<int, std::string>> vec(3);
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    timsort(vec, minrun);
    std::cout << vec << std::endl;
    return 0;
}