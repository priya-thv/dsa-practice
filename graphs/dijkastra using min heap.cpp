using set
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }

    set<pair<int,int>>st;
    dist[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        // fetch top record
        auto top=*(st.begin());

        int topdist=top.first;
        int topnode=top.second;
        // remove top record
        st.erase(st.begin());
        for(auto n:adj[topnode]){
            if(topdist+n.second < dist[n.first] ){
                auto record=st.find( make_pair(dist[n.first] , n.first) );
                if(record!=st.end()){
                    st.erase(record);
                }
                dist[n.first]=topdist+n.second;
                st.insert(make_pair(dist[n.first] , n.first));
            }
        }
    }
     return dist;
 }

using min heap
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src) {
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>weight(vertices,INT_MAX);
    weight[src]=0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({weight[src],src});
    while(!pq.empty()){
        int top=pq.top().second;
        pq.pop();
        for(auto t:adj[top]){
            int n=t.first;
            int w=t.second;
            if( weight[n]>=(weight[top]+w)){
                weight[n]=weight[top]+w;
                pq.push({weight[n],n});
            }
        }
    }
    return weight;
}



