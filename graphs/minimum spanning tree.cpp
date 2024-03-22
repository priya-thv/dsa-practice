#include<bits/stdc++.h>
bool cmp(vector<int>&a,vector<int>&b){
  return a[2]<b[2];
}
void makeset(vector<int>&parent,vector<int>&rank,int n){
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}


int checkparent(vector<int>& parent, int node) {
    while (parent[node] != node) {
        parent[node] = parent[parent[node]]; // Path compression
        node = parent[node];
    }
    return node;
}

void unionset(int u,int v,vector<int>&parent,vector<int>&rank){
  int x=checkparent(parent,u);
  int y=checkparent(parent,v);
  if(rank[x]>rank[y]){
    parent[y]=x;

  }else if(rank[y]>rank[x]){
    parent[x]=y;
  }else{
    parent[y]=x;
    rank[x]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
  sort(edges.begin(),edges.end(),cmp);
  vector<int>parent(n);
  vector<int>rank(n);
  makeset(parent,rank,n);
  int minweight=0;
  for(int i=0;i<edges.size();i++){
    int u=checkparent(parent, edges[i][0]);
    int v=checkparent(parent, edges[i][1]);
    int wt=edges[i][2];
    if(u!=v){
      minweight+=wt;
      unionset(u, v, parent, rank);
    }
  }
  return minweight;
}
