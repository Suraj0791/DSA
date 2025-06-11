#include <iostream>
#include <vector>
using namespace std;


// Enter number of nodes and edges: 5 6
// Is the graph directed? (1 for Yes, 0 for No): 0
// Enter 6 edges (u v):
// 0 1
// 0 4
// 1 2
// 1 3
// 1 4
// 3 4

// Adjacency List:
// 0 -> 1 4 
// 1 -> 0 2 3 4 
// 2 -> 1 
// 3 -> 1 4 
// 4 -> 0 1 3

// Use bool isDirected to handle both types of graphs.
// In contests, they tell you whether the graph is directed.
// Always check whether the graph uses 0-based or 1-based indexing



int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    bool isDirected;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    vector<vector<int>> adj(n); // adjacency list

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        // Add edge based on graph type
        adj[u].push_back(v);
        if (!isDirected) {
            adj[v].push_back(u);
        }
    }

    // Print the adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << " -> ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }

    return 0;
}
