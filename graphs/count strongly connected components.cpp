#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

void dfs(int node, vector<bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    for (auto n : adj[node]) {
        if (!visited[n]) {
            dfs(n, visited, s, adj);
        }
    }
    s.push(node);
}

void redfs(int node, vector<bool>& visited, unordered_map<int, list<int>>& trans) {
    visited[node] = true;
    for (auto n : trans[node]) {
        if (!visited[n]) {
            redfs(n, visited, trans);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    stack<int> s;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, visited, s, adj);
        }
    }

    // Transpose
    unordered_map<int, list<int>> trans;
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        for (auto n : adj[i]) {
            trans[n].push_back(i);
        }
    }

    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!visited[top]) {
            count++;
            redfs(top, visited, trans);
        }
    }
    return count;
}
