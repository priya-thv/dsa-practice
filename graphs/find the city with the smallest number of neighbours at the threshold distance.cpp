class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            while(!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                for(auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int w = neighbor.second;
                    if(dist[i][v] > d + w) {
                        dist[i][v] = d + w;
                        pq.push({dist[i][v], v});
                    }
                }
            }
        }
        
        int minReachable = n + 1; // Initialize with a value larger than n
        int result = -1;
        for(int i = 0; i < n; i++) {
            int reachable = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    reachable++;
                }
            }
            if(reachable <= minReachable) {
                minReachable = reachable;
                result = i;
            }
        }      
        return result;
    }
};
