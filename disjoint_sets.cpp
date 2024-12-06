#include <string>
#include "Timsort.cpp"

class DisjSet
{
    Vector<std::string> parents;
    Vector<std::string> vertices;

public:
    DisjSet() : parents(1), vertices(1) {};
    DisjSet(Vector<std::string> _vertices);
};

DisjSet::DisjSet(Vector<std::string> _vertices) : parents(1), vertices(1)
{
    for (int i = 0; i < _vertices.get_size(); i++)
    {
        parents.push_back(_vertices[i]);
        vertices.push_back(_vertices[i]);
    }
}