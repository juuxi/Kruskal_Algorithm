#include <iostream>
#include <algorithm>
#include "Timsort.cpp"
#include "adjacency_matrix.cpp"

int main()
{
    std::cout << "Alright!" << std::endl;
    std::ifstream f("adjacency_matrix.txt");
    int num_of_lines = std::count(std::istreambuf_iterator<char>(f), 
            std::istreambuf_iterator<char>(), '\n');
    f.seekg(0);
    AdjMatrix mtr(num_of_lines);
    mtr.write(f);
    std::cout << mtr;
    std::cout << std::endl;
    int minrun = count_minrun(num_of_lines);
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