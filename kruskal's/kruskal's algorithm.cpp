#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
char par[128];

char find(char c)
{
    while (par[(int)c] != -1)
        c = par[(int)c];
    return c;
}

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
void sortx(vector<Graph> &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x.size() - 1; j++)
        {
            if (x[j].w > x[j + 1].w)
            {
                swap(x[j], x[j + 1]);
            }
        }
    }
}
main()
{
    ofstream outfile;
    outfile.open("kru.txt");
    vector<Graph> x;
    vector<Graph> MST_edge_list;
    char u, v;
    int weight;
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
    sortx(x);
    for (int i = 0; i < 128; i++)
    {
        par[i] = -1;
    }
    for (int i = 0; i < x.size(); i++)
    {
        u = x[i].i;
        v = x[i].f;
        weight = x[i].w;
        if (find(u) != find(v))
        {
            par[find(u)] = find(v);
            MST_edge_list.push_back(x[i]);
        }
    }
    cout << "\nThe edges in the MST are:\n";
    for (int i = 0; i < MST_edge_list.size(); i++)
    {
        cout << MST_edge_list[i].i << " " << MST_edge_list[i].f << " " << MST_edge_list[i].w << "\n";
        outfile << MST_edge_list[i].i << " " << MST_edge_list[i].f << " " << MST_edge_list[i].w << "\n";

    }
}