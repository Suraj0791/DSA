#include <bits/stdc++.h>
using namespace std;

// for (int i = 0; i < V; i++) {
//     if (!visited[i]) {
//         if (isCycleBFS(i, adj, visited))
//             return true;
//     }
// }
// Why this loop?
// Because graph may be disconnected.
// So you have to check every unvisited component.



// Complexity	O(V + E) (same as BFS traversal)




bool isCycleBFS(int start, vector<int> adj[], vector<bool>& visited) {
    queue<pair<int, int>> q; // {current node, parent}
    visited[start] = true;
    q.push({start, -1}); // -1 as parent of starting node

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                // Already visited and not the parent → cycle found
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycleBFS(i, adj, visited))
                return true;
        }
    }
    return false;
}
