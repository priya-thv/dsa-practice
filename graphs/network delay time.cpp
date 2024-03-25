class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({dist[k],k});

        while(!pq.empty()){
            
            int c=pq.top().second;
            pq.pop();
            for(auto x:adj[c]){
                int u=x.first;
                int y=x.second;
                if(dist[u]>dist[c]+y){
                    dist[u]=dist[c]+y;
                    pq.push({dist[u],u});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i < n+1; ++i) {
            maxi = max(maxi, dist[i]);
        }
        
        if(maxi == INT_MAX) {
            return -1;
        }
        return maxi;
    }
};
