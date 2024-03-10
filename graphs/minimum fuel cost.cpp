class Solution {
public:
long  long ans=0;
    int dfs(int i,vector<bool>& visited,unordered_map<int,list<int>>& adj, int seats) {
        visited[i] = true;
        int count = 1;
        
        for (auto x : adj[i]) {
            if (!visited[x]) {
               count+= dfs(x, visited, adj, seats);
               
            }
        }
        if(i != 0)
        {
            ans += ceil((double) count / seats);
        }
        
        return count;
    }

    long long minimumFuelCost(std::vector<std::vector<int>>& roads, int seats) {
        

        std::unordered_map<int, std::list<int>> adj;
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::vector<bool> visited( roads.size()+1, false);
        
        dfs(0, visited, adj, seats);

        return ans;
    }
};
