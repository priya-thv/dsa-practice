#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(string start, string end, unordered_map<string, vector<pair<string, double>>>& adj, vector<string>& vis, double& count, double temp) {
        if(find(vis.begin(), vis.end(), start) != vis.end()) return;
        vis.push_back(start);
        if(start == end) {
            count = temp;
            return;
        }
        for(auto& n : adj[start]) {
            dfs(n.first, end, adj, vis, count, temp * n.second);
        }
    } 

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        // Constructing adjacency list
        for(int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 1.0 / w});
        }

        vector<double> ans;

        for(int i = 0; i < queries.size(); ++i) {
            string div = queries[i][0];
            string divs = queries[i][1];
            
            if(adj.find(div) == adj.end() || adj.find(divs) == adj.end()) {
                ans.push_back(-1.0);
            } else {
                vector<string> vis;
                double count = -1.0, temp = 1.0;
                dfs(div, divs, adj, vis, count, temp);
                ans.push_back(count);
            }
        }

        return ans;
    }
};
