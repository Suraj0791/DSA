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

// Adjacency Matrix:
// 0 1 0 0 1 
// 1 0 1 1 1 
// 0 1 0 0 0 
// 0 1 0 0 1 
// 1 1 0 1 0 


// This code supports both directed and undirected graphs.
// If the graph is weighted, we can replace 1 with the weight w in matrix[u][v] = w.   input given as u v w 
// Space complexity of adjacency matrix: O(n^2) — use only for dense graphs or when matrix logic is required.




int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    bool isDirected;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    // Initialize n x n matrix with 0s
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        matrix[u][v] = 1; // for directed graph
        if (!isDirected) {
            matrix[v][u] = 1; // for undirected graph
        }
    }

    // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
