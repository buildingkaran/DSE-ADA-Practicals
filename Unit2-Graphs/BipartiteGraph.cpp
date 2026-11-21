
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[26];
int color[26];

// Check Bipartite using BFS
bool isBipartite(int n)
{
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int start = 0; start < n; start++)
    {
        if (color[start] == -1)
        {
            queue<int> q;

            color[start] = 0;
            q.push(start);

            while (!q.empty())
            {
                int vertex = q.front();
                q.pop();

                for (int i = 0; i < adj[vertex].size(); i++)
                {
                    int neighbour = adj[vertex][i];

                    if (color[neighbour] == -1)
                    {
                        color[neighbour] = 1 - color[vertex];
                        q.push(neighbour);
                    }
                    else if (color[neighbour] == color[vertex])
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
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

    if (isBipartite(n))
    {
        cout << "The graph is Bipartite.";
    }
    else
    {
        cout << "The graph is NOT Bipartite.";
    }

    return 0;
}
