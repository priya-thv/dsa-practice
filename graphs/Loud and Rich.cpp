class Solution {
public:
    void dfs(unordered_map<int,list<int>>&adj,vector<int>& quiet,int node,vector<bool>&vis,
    int &x,int &qu){
        vis[node]=true;

        if(quiet[node]<qu){
            qu=quiet[node];
            x=node;
        }
        for(auto t:adj[node]){
            if(!vis[t]){
                dfs(adj,quiet,t,vis,x,qu);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int>v;
        unordered_map<int,list<int>>adj;
        for(int i=0;i<richer.size();i++){
            int u=richer[i][0];
            int v=richer[i][1];
            adj[v].push_back(u);
        }
        int n=quiet.size();
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            int x=-1,qu=INT_MAX;
            dfs(adj,quiet,i,vis,x,qu);
            v.push_back(x);
        }
        return v;
    }
};
