#include<bits/stdc++.h>
bool cmp(vector<int>&a,vector<int>&b){
	return a[2]<b[2];
}
int checkparent(vector<int>&parent,int node){
	while(parent[node]!=node){
		parent[node] = parent[parent[node]];
        node = parent[node];
	}
	return parent[node];
}
void unionset(int n,int m,vector<int>&parent,vector<int>&rank){
	int u=checkparent(parent,n);
	int v=checkparent(parent, m);
	if(rank[n]==rank[m]){
		parent[m]=n;
		rank[n]++;
	}
	if(rank[n]>rank[m]){
		parent[m]=n;
	}
	if(rank[n]<rank[m]){
		parent[n]=m;
	
	}

}
int kruskalMST(int n, vector<vector<int>> &edges)
{
	// Write your code here.
	sort(edges.begin(),edges.end(),cmp);
	vector<int>parent(n);
	vector<int>rank(n,0);
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	int weight=0;
    for(int i=0;i<edges.size();i++){
		int u=checkparent(parent,edges[i][0]);
		int v=checkparent(parent, edges[i][1]);
		int w=edges[i][2];
		if (u!=v){
            weight+=w;
			unionset(u,v,parent,rank);
		} 
	}
	return weight;
}
