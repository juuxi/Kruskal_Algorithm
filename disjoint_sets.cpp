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
    if (parents[second_index] != parents[first_index])
    {
        int finder = first_index;
        while(vertices[finder] != parents[finder])
            finder = vertices.find(parents[finder]);
        parents[second_index] = parents[finder];
    }
}

std::ostream& operator<< (std::ostream& os, DisjSet& ds)
{
    for (int i = 0; i < ds.vertices.get_size(); i++)
        os << ds.vertices[i] << " " << ds.parents[i] << "; ";
    return os;
}