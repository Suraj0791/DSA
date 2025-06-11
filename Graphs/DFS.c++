#include <bits/stdc++.h>

using namespace std;



class Solution {
  public:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;

        // In case of disconnected graph, iterate all nodes
        dfsHelper(0, adj, visited, ans);

        return ans;
    }
};
