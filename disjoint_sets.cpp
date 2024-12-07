#include <string>
#include "Timsort.cpp"

class DisjSet
{
    Vector<std::string> parents;
    Vector<std::string> vertices;

public:
    DisjSet() : parents(1), vertices(1) {};
    DisjSet(Vector<std::string> _vertices);
    void unionize(int first_index, int second_index);
    std::string find(std::string);
    int find_index(std::string);
    friend std::ostream& operator<< (std::ostream&, DisjSet&);
};

DisjSet::DisjSet(Vector<std::string> _vertices) : parents(1), vertices(1)
{
    for (int i = 0; i < _vertices.get_size(); i++)
    {
        parents.push_back(_vertices[i]);
        vertices.push_back(_vertices[i]);
    }
}

void DisjSet::unionize(int first_index, int second_index)
{
    if (parents[first_index] != parents[second_index])
    {
        int finder = second_index;
        while(vertices[finder] != parents[finder])
            finder = vertices.find(parents[finder]);
        parents[first_index] = parents[finder];
    }
}

std::string DisjSet::find(std::string _str)
{
    int index = vertices.find(_str);
    return parents[index];
}

int DisjSet::find_index(std::string _str)
{
    return vertices.find(_str);
}

std::ostream& operator<< (std::ostream& os, DisjSet& ds)
{
    for (int i = 0; i < ds.vertices.get_size(); i++)
        os << ds.vertices[i] << " " << ds.parents[i] << "; ";
    return os;
}