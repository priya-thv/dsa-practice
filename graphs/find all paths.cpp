// class Solution {
// public:
//     void dfs(vector<bool>&visited,int node,unordered_map<int,list<int>>&adj,stack<int>&s,int n){
//         visited[node]=true;
//         for(auto t:adj[node]){
//             if(t==n-1){
//                 s.push(node);
//             }
//             else if(!visited[t]){
//                 dfs(visited,t,adj,s,n);
//             }
//         }
        
//         if(!s.empty()){
//             s.push(node);
//         }
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         int n=graph.size();
//         unordered_map<int,list<int>>adj;
//         for(int i=0;i<graph.size();i++){
//             for(int j=0;j<graph[0].size();i++){
//                 int u=graph[i][j];
//                 adj[i].push_back(u);
//             }
//         }
//         vector<bool>visited(n,false);
//         stack<int>s;
//         for(int i=0;i<graph.size();i++){
//             if(!visited[i]){
//                 dfs(visited,i,adj,s,n);
//             }
//         }
//         vector<vector<int>>v;
//          vector<int>g;
//         while(!s.empty()){
//             int top=s.top();
//             s.pop();
           
//             g.push_back(top);
//         }
//         v.push_back(g);
//         return v;
//     }
// };
class Solution {
public:
    void dfs(vector<bool>& visited, int node, unordered_map<int, list<int>>& adj, stack<int>& s, int n, vector<vector<int>>& result) {
        visited[node] = true;
        s.push(node);

        if (node == n - 1) {
            vector<int> path;
            stack<int> tempStack = s;
            while (!tempStack.empty()) {
                path.push_back(tempStack.top());
                tempStack.pop();
            }
            reverse(path.begin(),path.end());
            result.push_back(path);
        } else {
            for (auto t : adj[node]) {
                if (!visited[t]) {
                    dfs(visited, t, adj, s, n, result);
                }
            }
        }

        s.pop();
        visited[node] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int u = graph[i][j];
                adj[i].push_back(u);
            }
        }

        vector<bool> visited(n, false);
        stack<int> s;
        vector<vector<int>> result;

        dfs(visited, 0, adj, s, n, result);

        return result;
    }
};

