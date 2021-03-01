#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool visited[128] = {};
int dist[128];

void relax(char u, char v, int w)
{
    dist[v] = min(dist[v], dist[u] + w);
}
void printSolution(char src)
{
    cout << "Minimum distance of all node from the node " << src << " is:\n";
    for (int i = 0;i < 128;i++)
    {
        if (dist[i] < 9999)
            cout << (char)i << " " << dist[i] << "\n";
    }
}

void dk(vector<pair<char, int>> adj_list[128], char src)
{

    for (int i = 0; i < 128; i++)
        dist[i] = 9999;
    int min_node = src;
    dist[src] = 0;
    while (min_node != -1)
    {
        visited[min_node] = 1;
        for (int i = 0; i < adj_list[min_node].size(); i++)
            relax(min_node, adj_list[min_node][i].first, adj_list[min_node][i].second);
        min_node = -1;
        for (int i = 0; i < 128; i++)
            if (dist[i] < 9999 && !visited[i])
            {
                if (min_node == -1)
                    min_node = i;
                else if (dist[i] < dist[min_node])
                    min_node = i;
            }
    }
}
main()
{
    ofstream outfile;
    outfile.open("dk.txt");
    vector<pair<char, int>> x[128];
    x['s'].push_back({'t', 10});
    x['s'].push_back({'y', 5});
    x['t'].push_back({'y', 2});
    x['y'].push_back({'t', 3});
    x['t'].push_back({'x', 1});
    x['y'].push_back({'x', 9});
    x['x'].push_back({'z', 4});
    x['z'].push_back({'x', 6});
    x['y'].push_back({'x', 9});
    x['z'].push_back({'s', 7});
    dk(x,'s');
    printSolution('s');
    for (int i = 0;i < 128;i++)
    {
        if (dist[i] < 9999)
            outfile<<(char)i << " " << dist[i] << "\n";
    }
}