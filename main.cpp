#include <iostream>
#include <algorithm>
#include "adjacency_matrix.cpp"
#include "disjoint_sets.cpp"

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

void get_vertices_names(Vector<std::string>& vertices, AdjMatrix& mtr)
{
     for (int i = 0; i < mtr.get_size(); i++)
    {
        if (i < 26)
        {
            std::string s = "";
            s += mtr.names[i];
            vertices.push_back(s);
        }
        else
        {
            std::string s = "A";
            s += mtr.names[i-26];
            vertices.push_back(s);
        }
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
    Vector<std::string> vertices(1);
    get_vertices_names(vertices, mtr);
    DisjSet ds(vertices);
    std::cout << ds << std::endl;
    ds.unionize(0, 1);
    ds.unionize(1, 2);
    std::cout << ds << std::endl;
    std::cout << ds.find("C") << std::endl;
    return 0;
}