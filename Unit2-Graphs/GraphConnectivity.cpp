
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[26];
bool visited[26];

// DFS function
void DFS(int vertex)
{
    visited[vertex] = true;

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

    cout << "Enter the edges (A B):" << endl;

    for (int i = 0; i < e; i++)
    {
        char u, v;
        cin >> u >> v;

        int x = u - 'A';
        int y = v - 'A';

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Start DFS from vertex A
    DFS(0);

    // Check whether all vertices are visited
    bool connected = true;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected = false;
            break;
        }
    }

    if (connected)
    {
        cout << "The graph is Connected.";
    }
    else
    {
        cout << "The graph is Disconnected.";
    }

    return 0;
}
