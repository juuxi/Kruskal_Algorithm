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
    {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    }
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

AdjMatrix::~AdjMatrix()
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}