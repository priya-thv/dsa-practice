#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<bool> mst(n + 1, false);

    key[1] = 0; // Starting vertex
    parent[1] = -1;

    for (int i = 1; i < n; i++) {
        int u = -1;
        for (int v = 1; v <= n; v++) {
            if (!mst[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        mst[u] = true;

        for (auto& t : adj[u]) {
            int v = t.first;
            int w = t.second;
            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}
