#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> x;
class Graph
{
public:
    char i;
    char f;
    int w;
    Graph(char i, char f, int w);
};
Graph::Graph(char i, char f, int w)
{
    this->i = i;
    this->f = f;
    this->w = w;
}
int dist[128];
void printArr(int arr[])
{
    int i;
    for (i = 0; i < 128; i++)
    {
        if (arr[i] == 9999)
        {
            continue;
        }
        else
        {
            cout << arr[i] << endl;
        }
    }
    printf("\n");
}
void bell(vector<Graph> &t, char src)
{
    for (int i = 0; i < 128; i++)
    {
        dist[i] = 9999;
    }
    int min_node = src;
    dist[src] = 0;
    x.push_back(dist[src]);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            char u = t[j].i;

            char f = t[j].f;
            int w = t[j].w;
            if (dist[u] != 9999 && dist[u] + w < dist[f])
            {

                dist[f] = dist[u] + w;
                x.push_back(dist[f]);
                break;
            }
        }
    }
}

main()
{
    ofstream outfile;
    outfile.open("bellman.txt");
    vector<Graph> t;
    t.push_back(Graph('s', 't', 6));
    t.push_back(Graph('s', 'y', 7));
    t.push_back(Graph('t', 'x', 5));
    t.push_back(Graph('t', 'y', 8));
    t.push_back(Graph('x', 't', -2));
    t.push_back(Graph('y', 'z', 9));
    t.push_back(Graph('z', 's', 2));
    t.push_back(Graph('t', 'z', -4));
    t.push_back(Graph('y', 'x', -3));
    bell(t, 's');
    for(auto k:x)
    {
        cout<<k<<endl;
        outfile<<k<<endl;
    }
}
