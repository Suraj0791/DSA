/*
    Company Tags  : Flipkart, Amazon, Samsung, MakeMyTrip, Oracle, Adobe
    Question Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/
#include <bits/stdc++.h>
using namespace std;

// ❓ Why the loop: for (int i = 0; i < V; i++)?
// Because the graph could be disconnected.

// ➡️ Example:
// Component 1: 0 - 1 - 2  
// Component 2: 3 - 4

// If you start DFS from 0, you only explore Component 1.
// You’d miss Component 2, and you wouldn’t know if it has a cycle.
// So you must check every unvisited node by looping over all vertices.


// ❓ Why if (visited[i] == false && isCycleUtil(...))?
// We only start a new DFS if the node hasn’t been visited yet.

// If DFS from that node finds a cycle, return true.

// ✅ Summary (Key Lines with Meaning)
// visited[start] = true;	Mark current node as visited
// if (*it == parent) continue;	Skip the node we came from
// if (visited[*it]) return true;	Found a cycle
// if (isCycleUtil(...)) return true;	Recursively check neighbor
// for (int i = 0; i < V; i++)	Ensure all disconnected parts are checked
// if (!visited[i])	Don't redo DFS on already visited components






bool isCycleUtil(vector<int> g[], int start, vector<bool>& visited, int parent) {
    visited[start] = true;
    
    vector<int>::iterator it;
    for(it = g[start].begin(); it != g[start].end(); it++) {
        if(*it == parent)
            continue;
        if(visited[*it] == true)
            return true;
        if(isCycleUtil(g, *it, visited, start))
            return true;
            
    }
    return false;
}

bool isCyclic(vector<int> g[], int V) {
    vector<bool> visited(V, false);
    
    for(int i = 0; i<V; i++) {
        if(visited[i] == false && isCycleUtil(g, i, visited, -1))
            return true;
    }
    return false;
