#include <vector>
#include <unordered_set>
using namespace std;

class Graph {
public:
    bool detectCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false); 
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && dfs(i, adj, visited, -1))
                return true; 
        }
        return false;
    }

    bool dfs(int v, vector<int> adj[], vector<bool>& visited, int parent) {
        visited[v] = true; 
       
        for (int u : adj[v]) {
            if (!visited[u]) { 
                if (dfs(u, adj, visited, v)) 
                    return true; 
            } else if (u != parent) { 
                return true; 
            }
        }
        return false; 
    }
};
