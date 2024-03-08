class Solution {
public:
     void dfs(vector<bool>& visited, unordered_map<int, list<pair<int, int>>>& adj, int i,int &mini) {
        visited[i] = true;

        for (auto n : adj[i]) {
            if (!visited[n.first]) {
                mini=min(mini,n.second);
                dfs(visited, adj, n.first,mini);
            }else {
                mini = min(mini, n.second);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int weight = roads[i][2];
            pair<int, int> p = make_pair(v, weight);
            pair<int, int> t = make_pair(u, weight);
            adj[u].push_back(p);
            adj[v].push_back(t);
        }

        vector<bool> visited(n + 1, false);
        
        int mini=INT_MAX;
        
        dfs(visited, adj, 1,mini);
       
        return mini;
    }
};
