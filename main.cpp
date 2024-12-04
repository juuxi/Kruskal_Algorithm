#include <iostream>
#include <algorithm>
#include "Timsort.cpp"
#include "adjacency_matrix.cpp"

void get_edge_name(int i, int j, std::string& str, AdjMatrix& mtr)
{
    if (i < 26)
        str.push_back(mtr.names[i]);
    else
    {
        str.push_back('A');
        str.push_back(mtr.names[i-26]);
    } 
    str.push_back(' ');   
    if (j < 26)
        str.push_back(mtr.names[j]);
    else
    {
        str.push_back('A');
        str.push_back(mtr.names[j-26]);
    }   
}

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
    Vector<Pair<int, std::string>> vec(1);
    for (int i = 0; i < mtr.get_size(); i++)
    {
        for (int j = i + 1; j < mtr.get_size(); j++)
        {
            if (mtr[i][j] == 0)
                continue;
            std::string str;
            get_edge_name(i, j, str, mtr);
            vec.push_back(Pair<int, std::string>(mtr[i][j], str));
        }
    }
    timsort(vec, minrun);
    std::cout << vec << std::endl;
    return 0;
}