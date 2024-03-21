#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    unordered_map<int,list<int>>adj;
    vector<int>indegree(nodes,0);
    vector<int>t;
    for(int i=0;i<edges;i++){
       int u=graph[i][0];
       int v=graph[i][1];
       adj[u].push_back(v);
       indegree[v]++;
    }
    vector<int>visited(nodes);
    queue<int>q;
    for(int i=0;i<nodes;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        t.push_back(front);
        visited[front]=true;
        for(auto t:adj[front]){
            indegree[t]--;
            if(indegree[t]==0){
                q.push(t);
            }
        }

    }
    return t;

}
