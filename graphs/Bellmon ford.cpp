

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    int INF = 1e8; 
    vector<int> dist(n + 1, INF); 
    dist[src] = 0; 

    
    for (int i = 1; i < n ; ++i) {
        for (int j = 0; j < m; ++j) { 
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

   


    // if (hasNegativeCycle) {
    //     return vector<int>();
    // }

    return dist;
}


