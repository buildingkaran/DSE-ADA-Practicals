
#include <iostream>
using namespace std;

int main()
{
    int n, e;
    int cost[26][26] = {0};
    bool visited[26] = {false};

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges (A B Weight):" << endl;

    for (int i = 0; i < e; i++)
    {
        char u, v;
        int w;

        cin >> u >> v >> w;

        int x = u - 'A';
        int y = v - 'A';

        cost[x][y] = w;
        cost[y][x] = w;
    }

    // Start from vertex A
    visited[0] = true;

    int edgeCount = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edgeCount < n - 1)
    {
        int minWeight = 1000000;
        int x = -1, y = -1;

        // Find minimum edge connecting visited to unvisited
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] != 0)
                    {
                        if (cost[i][j] < minWeight)
                        {
                            minWeight = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        if (x == -1)
        {
            cout << "Graph is disconnected. MST not possible.";
            return 0;
        }

        cout << char(x + 'A') << " - "
             << char(y + 'A') << " : "
             << minWeight << endl;

        totalCost += minWeight;
        visited[y] = true;
        edgeCount++;
    }

    cout << "\nMinimum Cost of MST: " << totalCost;

    return 0;
}
