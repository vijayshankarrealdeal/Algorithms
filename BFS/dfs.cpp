#include<iostream>
#include<list>
#include<fstream>
using namespace std;

class Graph
{
    int Vertex;
    list<int> *adjList;
    void DFSUtil(int v, bool visited[]);
    void APUtil(int v, bool visited[], int disc[], int low[],int parent[], bool ap[]); 
    bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
    void AP(); 
    bool isCyclic();  
    void print(){
            ofstream outfile;
            outfile.open("dfs.txt");
        for(int i =1;i<Vertex+1;i++)
        {
            cout<<i<<"\n";
            for(auto x:adjList[i])
            {
                cout<<x<<"\t";
                outfile<<x<<"\t";
            }
            cout<<"\n";
        }
    }
};
bool Graph::isCyclic() 
{  
    bool visited[Vertex]; 
    bool recStack[Vertex]; 
    for(int i = 0; i < Vertex; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
    for(int i = 0; i < Vertex; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 
bool Graph::isCyclicUtil(int v, bool visited[], bool recStack[]) 
{ 
    if(visited[v] == false) 
    { 
        visited[v] = true; 
        recStack[v] = true;   
        list<int>::iterator i; 
        for(i = adjList[v].begin(); i != adjList[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
            {
                return true; 
            }
            else if (recStack[*i]) 
            {
                return true; 
            }
        } 
  
    } 
    recStack[v] = false;
    return false; 
}

Graph::Graph(int V)
{
    this->Vertex = V;
    adjList = new list<int>[V+1];
}

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{

    visited[v] = true;      
    cout << v << " ";
    list<int>::iterator i;
    for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
    {
        if (!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int v)
{
    bool visited[Vertex];
    for (int i = 0; i < Vertex; i++)
    {
        visited[i] = false;
    }
    DFSUtil(v, visited);
}
void Graph::APUtil(int u, bool visited[], int discover_time[],  int low_value[], int parent[], bool ap[]) 
{ 

    static int time = 0; 
    int children = 0; 
    visited[u] = true; 
    discover_time[u] = low_value[u] = ++time; 
    list<int>::iterator i; 
    for (i = adjList[u].begin(); i != adjList[u].end(); ++i) 
    { 
        int v = *i;    
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, discover_time, low_value, parent, ap); 
            low_value[u]  = min(low_value[u], low_value[v]);             
            if (parent[u] == NULL && children > 1) 
               ap[u] = true; 
            if (parent[u] != NULL && low_value[v] >= discover_time[u]) 
               ap[u] = true; 
        } 
        else if (v != parent[u]) 
            low_value[u]  = min(low_value[u], discover_time[v]); 
    } 
} 
  
void Graph::AP() 
{ 
    bool *visited = new bool[Vertex]; 
    int *discover_time = new int[Vertex]; 
    int *low_value = new int[Vertex]; 
    int *parent = new int[Vertex]; 
    bool *ap = new bool[Vertex]; 
    for (int i = 0; i < Vertex; i++) 
    { 
        parent[i] = NULL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
  
    for (int i = 0; i < Vertex; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, discover_time, low_value, parent, ap); 
    for (int i = 0; i < Vertex; i++) 
        if (ap[i] == true) 
            cout << i << " "; 
}

int main()
{

    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 6);
    g.addEdge(4, 1);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 2);
    g.addEdge(5, 6);
    g.addEdge(6, 2);
    g.addEdge(6, 3);
    g.addEdge(6, 5);
    g.addEdge(7, 8);
    g.addEdge(7, 4);
    g.addEdge(8, 4);
    g.addEdge(8, 7);
    g.print();
    cout<<"\n";
    cout<<"the articulation points --> \t";g.AP();
    cout<<"\n";
    cout<<"DFS --> \t";g.DFS(2);
    cout<<"\n";
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0;
}