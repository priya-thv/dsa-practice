#include <bits/stdc++.h>
using namespace std;

void shortpath(int src, unordered_map<int, list<pair<int, int>>>& adj, vector<int>& weights, vector<bool>& visited) {
    visited[src] = true;
    for (auto t : adj[src]) {
        int neighbor = t.first;
        int weight = t.second;
        if (!visited[neighbor] && weights[neighbor] >= (weights[src] + weight)) {
            weights[neighbor] = weights[src] + weight;
            shortpath(neighbor, adj, weights, visited);
        }
    }
    visited[src] = false;
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>>& edges) {
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v, w));
    }
    vector<int> weights(n, INT_MAX);
    vector<bool> visited(n, false);
    weights[0] = 0;
    shortpath(0, adj, weights, visited);
    for(int i=0;i<weights.size();i++){
        if(weights[i]==INT_MAX){
            weights[i]=-1;
        }
    }
    return weights;
}
