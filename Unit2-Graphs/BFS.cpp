
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[26];
bool visited[26];

// BFS function
void BFS(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << char(vertex + 'A') << " ";

        for (int i = 0; i < adj[vertex].size(); i++)
        {
            int neighbour = adj[vertex][i];

            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
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

        // Undirected graph
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    char start;

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start - 'A');

    return 0;
}
