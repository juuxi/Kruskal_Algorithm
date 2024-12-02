#include <iostream>
#include <fstream>
#include <string>

class AdjMatrix
{
    int size;
    int** matrix;
public:
    AdjMatrix(int);
    friend std::ostream& operator<< (std::ostream&, AdjMatrix&);
    void write(std::ifstream&);
    ~AdjMatrix();
};

AdjMatrix::AdjMatrix(int _size)
{
    size = _size;
    matrix = new int*[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
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
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = str[j]-'0';
            str.erase(j, 1);
        }
    }
}

AdjMatrix::~AdjMatrix()
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}