#include<bits/stdc++.h>
bool cycle(unordered_map<int,list<int>>&adj,int node,vector<bool>&visited,vector<bool>&dfs){
	visited[node]=1;
	dfs[node]=1;
	for(auto t:adj[node]){
		if(!visited[t]) {
            if(cycle(adj, t, visited, dfs))
                return true;
        } else if(dfs[t]) {
            return true;
        }
	}
	// visited[node]=0;
	dfs[node]=0;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	unordered_map<int,list<int>>adj;
	for(int i=0;i<e;i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	vector<bool>visited(v,0);
	vector<bool>dfs(v,0);
	for(int i=0;i<v;i++){
		if(!visited[i]){
			bool ans= cycle(adj,i,visited,dfs);
                        if (ans) {
                          return true;
                        }
                }
	}
	
	return false;
}
