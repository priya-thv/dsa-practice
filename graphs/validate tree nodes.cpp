class Solution {
public:
    bool dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int child : adj[node]) {
            if (!visited[child]) {
                if (!dfs(child, adj, visited))
                    return false;
            } else  {
                return false;
            }
        }
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, list<int>> adj;
        vector<int> parentCount(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                adj[i].push_back(leftChild[i]);
                parentCount[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                adj[i].push_back(rightChild[i]);
                parentCount[rightChild[i]]++;
            }
        }
        
        int rootCount = 0;
        int rootNode = -1;
        for (int i = 0; i < n; ++i) {
            if (parentCount[i] == 0) {
                rootCount++;
                rootNode = i;
            } else if (parentCount[i] > 1) {
                return false;
            }
        }
        
        if (rootCount != 1) {
            return false;
        }

        vector<bool> visited(n, false);
        if (!dfs(roootNode,adj,visited){
            return false;
        }
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        
        return true;
    }
};
