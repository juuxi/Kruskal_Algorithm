#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>

class AdjMatrix
{
    int size;
    int** matrix;
    std::vector<int> visited;
public:
    char names[26];

    AdjMatrix(int);
    friend std::ostream& operator<< (std::ostream&, AdjMatrix&);
    int*& operator[](int);
    bool are_edged(int i, int j);
    int get_size();
    void dfs(int);
    void write(std::ifstream&);
    ~AdjMatrix();
};

AdjMatrix::AdjMatrix(int _size)
{
    size = _size;
    matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    }
    std::iota(std::begin(names), std::end(names), 'A');
}


std::ostream& operator<< (std::ostream& os, AdjMatrix& am)
{
    for (int i = 0; i < am.size; i++)
    {
        for (int j = 0; j < am.size; j++)
            os << am.matrix[i][j] << " ";
        os << "\n";
    }
    return os;
}

void AdjMatrix::write(std::ifstream& ifs)
{
    std::string str;
    if (!ifs)
        return;
    getline(ifs, str);
    for (int i = 0; i < size; i++)
    {
        getline(ifs, str);
        int curr_col = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ' ')
            {
                curr_col++;
                continue;
            }
            matrix[i][curr_col] *= 10;
            matrix[i][curr_col] += str[j]-'0';
        }
    }
}

int*& AdjMatrix::operator[](int index)
{
    return matrix[index];
}

bool AdjMatrix::are_edged(int i, int j)
{
    if (matrix[i][j] == 0)
        return false;
    return true;
}

int AdjMatrix::get_size()
{
    return size;
}

void AdjMatrix::dfs(int index)
{
    visited.push_back(index);
    for (int i = 0; i < size; i++)
    {
        bool is_visited = std::find(visited.begin(), visited.end(), i) != visited.end();
        if (matrix[i][index] && !is_visited)
            dfs(i);
    }
    std::string s;
    if (index < 26)
        s += 'A' + index;
    else
    {
        s += 'A';
        s += 'A' + (index % 26);
    }
    std::cout << s << " ";
}

AdjMatrix::~AdjMatrix()
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}