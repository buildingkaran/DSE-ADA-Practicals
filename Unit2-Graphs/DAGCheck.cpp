
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[26];
int indegree[26] = {0};

int main()
{
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter directed edges (A B):" << endl;

    for (int i = 0; i < e; i++)
    {
        char u, v;
        cin >> u >> v;

        int x = u - 'A';
        int y = v - 'A';

        adj[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;

    // Add vertices having indegree 0
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;

    // Process vertices using BFS
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        count++;

        for (int i = 0; i < adj[vertex].size(); i++)
        {
            int neighbour = adj[vertex][i];

            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if (count == n)
    {
        cout << "The graph is a DAG (No Cycle).";
    }
    else
    {
        cout << "The graph contains a Cycle. It is NOT a DAG.";
    }

    return 0;
}
