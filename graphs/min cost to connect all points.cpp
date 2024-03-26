class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {  // Corrected the loop condition here
                int sum = (abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])); // Corrected the calculation of sum
                adj[i].push_back({ j, sum });
                adj[j].push_back({ i, sum }); // Since it's an undirected graph
            }
        }
        vector<int> key(points.size(), INT_MAX);
        vector<int> parent(points.size(), -1);
        vector<bool> visited(points.size(), false);

        int weight = 0;
        key[0] = 0;
        parent[0] = -1;
        for (int i = 0; i < n - 1; i++) {   //loop run for n-1 edges
            int u = -1;
            for (int v = 0; v < n; v++) { // Corrected the loop condition here
                if (!visited[v] && (u == -1 || key[v] < key[u])) {
                    u = v;
                }
            }
            visited[u] = true;
            for (auto t : adj[u]) {
                int f = t.first;
                int s = t.second;
                if (!visited[f] && s < key[f]) {
                    key[f] = s;
                    parent[f] = u;
                }
            }
        }
        for (auto t : key) {
            weight += t;
        }
        return weight;
    }
};
