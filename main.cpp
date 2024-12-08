#include <iostream>
#include <algorithm>
#include <queue>
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

void edges_insert_sort(Vector<std::string> &arr, size_t left, size_t right)
{
    for(size_t i = left + 1; i < right; i++)
    {
        std::string value = arr[i];
        for (int j = i-1; j >= left && value < arr[j]; j--)
        {
            std::string temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    } 
} 

void menu()
{
    std::cout << "1. - Обход в глубину" << std::endl;
    std::cout << "2. - Обход в ширину" << std::endl;
    std::cout << "3. - Алгоритм Крускала" << std::endl;
    std::cout << "4. - Выход" << std::endl << "> ";
}

int main()
{
    std::ifstream f("adjacency_matrix.txt");
    int num_of_lines = std::count(std::istreambuf_iterator<char>(f), 
            std::istreambuf_iterator<char>(), '\n');
    f.seekg(0);
    AdjMatrix mtr(num_of_lines);
    mtr.write(f);
    //std::cout << mtr;
    //std::cout << std::endl;
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
    Vector<std::string> vertices(1);
    get_vertices_names(vertices, mtr);
    DisjSet ds(vertices);
    Vector<std::string> edges(1);
    int sum_weight = 0;
    for (int i = 0; i < vec.get_size(); i++)
    {
        std::string vert_1 = vec[i].s();
        vert_1 = vert_1.substr(0, vert_1.find(' '));
        std::string vert_2 = vec[i].s();
        vert_2 = vert_2.substr(vert_2.find(' ') + 1, vert_2.size());

        if (ds.find(vert_1) != ds.find(vert_2))
        {
            edges.push_back(vert_1 + ' ' + vert_2);
            ds.unionize(ds.find_index(vert_1), ds.find_index(vert_2));
            sum_weight += vec[i].f();
            //std::cout << ds << std::endl;
        }
    }
    edges_insert_sort(edges, 0, edges.get_size());
    char c = '\0';
    while (c != '4')
    {
        system("clear");
        menu();
        std::cin >> c;
        switch(c)
        {
            case '1':
                break;
            case '2':
            {
                std::queue<std::string> q;
                Vector<std::string> visited(1);
                q.push("A");
                visited.push_back("A");
                while (!q.empty())
                {
                    std::string curr = q.front();
                    q.pop();
                    std::cout << curr;
                    for (int i = 0; i < mtr.get_size(); i++)
                    {
                        int j = ds.find_index(curr);
                        if(mtr.are_edged(i, j))
                        {
                            std::string to_push = "";
                            if (i < 26)
                                to_push += mtr.names[i];
                            else 
                            {
                                to_push += 'A';
                                to_push += mtr.names[i % 26];
                            }
                            if (visited.find(to_push) == -1)
                            {
                                q.push(to_push);
                                visited.push_back(to_push);
                            }
                        }
                    }
                }
                std::cin.ignore();
                std::cout << std::endl << "Нажмите Enter для продолжения ";
                std::cin.ignore();
                break;
            }
            case '3':
                std::cout << edges << std::endl;
                std::cout << sum_weight << std::endl;
                std::cin.ignore();
                std::cout << std::endl << "Нажмите Enter для продолжения ";
                std::cin.ignore();
                break;
            case '4':
                break;
            default: break;
        }
    }
    return 0;
}