#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    bool cycle(unordered_map<int, list<int>>& adj, vector<bool>& visited, vector<int>& state, int i, set<int>& ans, vector<bool>& dfs) {
        visited[i] = true;
        dfs[i] = true;
        state[i] = 1;

        for (auto x : adj[i]) {
            if (!visited[x]) {
                if (cycle(adj, visited, state, x, ans, dfs)) {
                    ans.insert(i);
                    return true;
                }
            } else if (dfs[x]) {
                ans.insert(i);
                return true;
            } else if (state[x] == 1) {
                ans.insert(i);
                return true;
            }
        }

        dfs[i] = false;
        state[i] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, list<int>> adj;
        vector<int> state(graph.size(), 0);  // 0: unvisited, 1: visiting, 2: visited
        set<int> ans;

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<bool> dfs(graph.size(), false);
        vector<bool> visited(graph.size(), false);

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                cycle(adj, visited, state, i, ans, dfs);
            }
        }

        vector<int> answer;
        for (int i = 0; i < graph.size(); i++) {
            if (ans.find(i) == ans.end()) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};
