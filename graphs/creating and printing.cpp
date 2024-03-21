#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;
    vector<vector<int>> v(n);
    
    // Populate adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int t = edges[i][1];
        adj[u].push_back(t);
        adj[t].push_back(u);
    }
    
    // Convert adjacency list to vector
     for (int i = 0; i < n; i++) {
        vector<int> c;
        c.push_back(i); // Vertex

        for (auto j : adj[i]) {
            c.push_back(j); // Adjacent vertices
        }
        v[i] = c;
    }
    
  
    return v;
}
