
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];
bool visited[100];

// DFS function
void DFS(int vertex)
{
    visited[vertex] = true;

    cout << vertex << " ";

    for (int i = 0; i < adj[vertex].size(); i++)
    {
        int neighbour = adj[vertex][i];

        if (!visited[neighbour])
        {
            DFS(neighbour);
        }
    }
}

int main()
{
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter the edges (u v):" << endl;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
