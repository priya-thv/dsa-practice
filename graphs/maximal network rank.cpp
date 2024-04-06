class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<int>> adj;
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int rank = adj[i].size();
                for(auto x:adj[j]){
                    if(x!=i){
                        rank++;
                    }
                }
                maxi=max(maxi,rank);
            }
        }
        return maxi;
    }
};
