
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int parent[26], rankArr[26];

// Find the parent of a vertex
int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

// Join two different sets
void unite(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a != b) {
        if (rankArr[a] < rankArr[b])
            swap(a, b);

        parent[b] = a;

        if (rankArr[a] == rankArr[b])
            rankArr[a]++;
    }
}

int main() {
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    Edge edges[100];

    cout << "Enter edges (Vertex1 Vertex2 Weight):\n";

    for (int i = 0; i < e; i++) {
        char u, v;
        cin >> u >> v >> edges[i].weight;

        edges[i].u = u - 'A';
        edges[i].v = v - 'A';
    }

    // Sort edges by increasing weight
    sort(edges, edges + e, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Initially, every vertex is its own parent
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // Select edge only if it does not form a cycle
        if (findParent(u) != findParent(v)) {
            cout << char(u + 'A') << " - "
                 << char(v + 'A') << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;
            unite(u, v);
            count++;

            if (count == n - 1)
                break;
        }
    }

    if (count != n - 1)
        cout << "Minimum Spanning Tree is not possible. Graph is disconnected.\n";
    else
        cout << "Total Minimum Cost: " << totalCost << endl;

    return 0;
}
