#include<bits/stdc++.h>
void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>>&result,
unordered_map<int,list<int>>&adj,vector<bool>&vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    for(auto n:adj[node]){
        if(n==parent){
            continue;
        }
        if(!vis[n]){
             dfs(n,node,timer,disc,low,result,adj,vis);
             low[node]=min(low[node],low[n]);
             if(low[n]>disc[node]){
                 vector<int>ans;
                 ans.push_back(node);
                 ans.push_back(n);
                 result.push_back(ans);
             }
        }
        else{
            low[node]=min(low[node],disc[n]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int>disc(v,0);
    vector<int>low(v,0);
    int parent=-1;
    vector<bool>vis(v,false);
    vector<vector<int>>result;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;
}
