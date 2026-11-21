
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

        // Directed edge from u to v
        adj[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;

    // Add vertices with indegree 0
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    cout << "Topological Sorting: ";

    int count = 0;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << char(vertex + 'A') << " ";
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

    if (count != n)
    {
        cout << "\nGraph contains a cycle. Topological sorting is not possible.";
    }

    return 0;
}
