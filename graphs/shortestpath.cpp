#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++){
		adj[edges[i].first].push_back(edges[i].second);
		adj[edges[i].second].push_back(edges[i].first);
	}

	vector<bool>visited(n,false);
	unordered_map<int,int>parent;
	queue<int>q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(auto x:adj[front]){
			if(!visited[x]){
				visited[x]=true;
				parent[x]=front;
				q.push(x);
			}
		}
	}

	vector<int>ans;
	int currnode=t;
	ans.push_back(t);
	while(currnode!=s){
		currnode=parent[currnode];
		ans.push_back(currnode);
	}
    reverse(ans.begin(),ans.end());
	return ans;

}
