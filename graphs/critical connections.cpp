class Solution {
public:
    void dfs(int node ,int &parent,vector<int>&disc,unordered_map<int,list<int>>&adj,vector<int>&low,
    vector<bool>&vis,vector<vector<int>>&ans,int &timer){
        vis[node]=true;
        disc[node]=low[node]=timer++;
        for(auto n:adj[node]){
            if(n==parent){
                continue;
            }
            if(!vis[n]){
                dfs(n,node,disc,adj,low,vis,ans,timer);
                low[node]=min(low[node],low[n]);
                // bridge
                if(low[n]>disc[node]){
                    vector<int>result;
                    result.push_back(node);
                    result.push_back(n);
                    ans.push_back(result);
                }
            }else{
                low[node]=min(low[node],low[n]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer=0;
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<bool>vis(n,false);
        vector<vector<int>>ans;
        int parent=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,parent,disc,adj,low,vis,ans,timer);
            }
        }
        return ans;
    }
};
