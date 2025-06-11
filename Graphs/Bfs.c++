#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> bfs;
        int V = adj.size(); // Fix: derive V from adj
        vector<bool> visited(V, false); // to keep track of visited vertices

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            // Traverse all neighbors of current node in given order
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfs;
    }
};
