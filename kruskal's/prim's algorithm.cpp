#include <iostream>
#include <vector>
using namespace std;
class Graph
{
public:
    char i;
    char f;
    int w;
    Graph(char x, char y, int t);
};
Graph::Graph(char x, char y, int t)
{
    this->i = x;
    this->f = y;
    this->w = t;
}
main()
{
    vector<Graph> x;
    x.push_back(Graph('a', 'b', 4));
    x.push_back(Graph('h', 'a', 8));
    x.push_back(Graph('b', 'h', 11));
    x.push_back(Graph('b', 'c', 8));
    x.push_back(Graph('c', 'i', 2));
    x.push_back(Graph('h', 'i', 7));
    x.push_back(Graph('g', 'h', 1));
    x.push_back(Graph('g', 'i', 6));
    x.push_back(Graph('f', 'g', 2));
    x.push_back(Graph('c', 'f', 4));
    x.push_back(Graph('c', 'd', 7));
    x.push_back(Graph('d', 'e', 9));
    x.push_back(Graph('d', 'f', 14));
    x.push_back(Graph('e', 'f', 10));


    for(int i =0 ;i<x.size();i++)
    {
           cout<<x[i].i<<"\t"<<x[i].f<<"\t"<<x[i].w<<"\n";
    }
}