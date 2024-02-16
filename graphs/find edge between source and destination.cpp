
class Solution {
public:
    
    bool vis(vector<vector<int>>&graph,int current, int destination, vector<bool>& visited) {
        if (current == destination) {
            return true;
        }
        visited[current] = true;
        for (const auto& x : graph[current]) {
            if (!visited[x] && vis(graph,x, destination, visited)) {
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
       
        vector<bool> visited(n, false);
       return vis(graph,source, destination, visited);
    }
};
