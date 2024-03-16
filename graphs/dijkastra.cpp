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
