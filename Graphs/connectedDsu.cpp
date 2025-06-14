#include<bits/stdc++.h>
using namespace std;

// If we try to union(x, y) and they already have the same parent, it means this cable is redundant — we don’t need it to connect anything → it’s an extra cable.

// To connect k disconnected components, you need at least k - 1 cables.
//  This line checks if we have enough extra cables to connect all the components.
// Let’s break it:

// To connect components into one big network, we need components - 1 cables.

// E.g., if we have 4 components: 🟢 🟠 🔵 🔴 → We need 3 cables to link them all.

// If we have enough extra cables, then the answer is components - 1.

// If not enough, it's impossible to connect the whole network → return -1.



// // ### ✅ This counts the number of **connected components**.

// // **Why does `parent[i] == i` mean it's a component root?**

// Because in DSU:
// - When you do `unionSet(x, y)`, you update one’s parent to the other.
// - Only the **leader (root)** of each group remains its own parent.
// - So if `parent[i] == i`, it means `i` is the **representative (root)** of one component.

// Thus, this loop counts **how many separate networks** (components) currently exist.

// ---

// ### ```cpp
// return (extraCables >= components - 1) ? (components - 1) : -1;


class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) 
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unionSet(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        // Union by rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough cables

        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;

        int extraCables = 0;

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            int parentU = find(u);
            int parentV = find(v);

            if (parentU == parentV) {
                // Already connected — extra cable
                extraCables++;
            } else {
                unionSet(u, v);
            }
        }

        // Count disconnected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) components++;
        }

        // To connect all components, we need (components - 1) cables
        return (extraCables >= components - 1) ? (components - 1) : -1;
    }
};
