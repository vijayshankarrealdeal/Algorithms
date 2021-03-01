#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include<fstream>
using namespace std;
int main()
{
    ofstream outfile;
    outfile.open("bfs.txt");
    vector<char> adj[128];
    bool visited[128] = {};
    vector<char> bfs_travarsal;
    adj['r'].push_back('s');
    adj['r'].push_back('v');
    adj['v'].push_back('s');
    adj['v'].push_back('w');
    adj['v'].push_back('y');
    adj['v'].push_back('u');
    adj['s'].push_back('r');
    adj['s'].push_back('v');
    adj['s'].push_back('w');
    adj['w'].push_back('s');
    adj['w'].push_back('t');
    adj['w'].push_back('x');
    adj['t'].push_back('x');
    adj['t'].push_back('w');
    adj['x'].push_back('t');
    adj['x'].push_back('w');
    adj['u'].push_back('v');
    adj['u'].push_back('y');
    adj['y'].push_back('v');
    adj['y'].push_back('u');
    queue<char> Q;
    Q.push('r');
    visited['r'] = 1;
    vector<int> count;
    int countx = 0;
    while (!Q.empty())
    {
        char node = Q.front();
        bfs_travarsal.push_back(node);
        Q.pop();
        for (auto child : adj[node])
            if (!visited[child])
            {
                visited[child] = 1;
                Q.push(child);
            }
            else
            {
                countx++;
                count.push_back(countx);
            }
        countx = 0;
    }
    cout << "BFS travarsalof the given input graph is: ";
    for (auto x : bfs_travarsal)
        cout << x << " ";
    
    for(int i = 0;i<bfs_travarsal.size();i++)
    {
        outfile<<bfs_travarsal[i];
    }
    cout << "\n";
    for (auto x : count)
        if (x == 2)
        {
            cout << "Cyclc is present";
            break;
        }
    cout << "\n";
}
