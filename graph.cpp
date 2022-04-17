#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <list>
using namespace std;
// implementing undirected graph using adjacency list
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// implementing directed graph using adjacency list
void addEdge2(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
// printing/Traversing the elements of graph
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
// //breadth first search of graph
void BFS(vector<int> adj[], int v, bool visited[], int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        // cout<<u<<" ";
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSDis(vector<int> adj[], int v)
{
    int c = 0;
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            c++;
            BFS(adj, v, visited, i);
        }
    }
    cout << c << endl;
}
// //topological sort using Kahn's BFS based algorithm
void TopSorting(vector<int> adj[], int v)
{
    vector<int> inDeg(v, 0);
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        for (auto x : adj[i])
        {
            inDeg[x]++;
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto v : adj[u])
        {
            if (--inDeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
// shortest path in a unweighted graph
void shortDis(vector<int> adj[], int v, int s)
{
    int dist[v];
    int vist[v];
    for (int i = 0; i < v; i++)
    {
        dist[v] = 0;
        vist[v] = 0;
    }
    queue<int> q;
    q.push(s);
    vist[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (vist[v] == 0)
            {
                dist[v] = dist[u] + 1;
                vist[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << dist[i] << endl;
    }
}

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSRec(adj, u, visited);
        }
    }
}
void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        DFSRec(adj, s, visited);
        cout << "\n";
    }
}
int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge2(adj, 0, 2);
    addEdge2(adj, 1, 0);
    addEdge2(adj, 2, 3);
    addEdge2(adj, 2, 1);
    addEdge2(adj, 3, 4);
    addEdge2(adj, 4, 3);
    // addEdge2(adj,7,8);
    printGraph(adj, v);
    // BFSDis(adj,v);
    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,1,3);
    // addEdge(adj,2,3);
    // addEdge(adj,2,4);
    // addEdge(adj,3,5);
    // addEdge(adj,4,5);
    // printGraph(adj,v);
    // TopSorting(adj,v);
    // shortDis(adj,v,0);
    DFS(adj, v, 0);
    return 0;
}
