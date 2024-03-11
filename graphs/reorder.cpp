// class Solution {
// public:
//     void bfs(unordered_map<int,list<int>>&adj,vector<int>&visited,int &count,int i,queue<int>&q){
//         visited[i]=true;
//         q.push(i);
//         while(!q.empty()){
//             int front=q.front();
//             q.pop();
//             for(auto x:adj[front]){
//                 if(!visited[x]){
//                     // count++;
//                     visited[x]=true;
//                     q.push(x);
//                     for(auto j:adj[x]){
//                         if (!visited[j]) {
//                             visited[j] = true;
//                             if (j != 0) {
//                                 count++;
//                             } else {
//                                 count--;
//                             }
//                         }
//                     }
                   
//                 }
//             }

//         }

//     }
//     int minReorder(int n, vector<vector<int>>& connections) {
//         unordered_map<int,list<int>>adj;
//         for(int i=0;i<connections.size();i++){
//             int u=connections[i][0];
//             int v=connections[i][1];
//             adj[u].push_back(v);
//              adj[v].push_back(u);
//         }
        
//         vector<int>visited(n,false);
//         queue<int>q;
//         int count=0;
        
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 bfs(adj,visited,count,i,q);
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    void bfs(unordered_map<int, list<int>>& adj, vector<int>& visited, int& count, int i, queue<int>& q,unordered_map<int, list<int>>& graph) {
        // visited[i] = true;
         q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            visited[node]=1;
            q.pop();
            for(auto x:graph[node]){
                if(!visited[x])
                {
                    q.push(x);
                    for(auto j:adj[x])
                    if(j==node) count--;
                    count++;
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adj,graph;
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            adj[u].push_back(v);
              // Add this line for both directions in a directed graph
        }

        vector<int> visited(n, false);
        queue<int> q;
        int count = 0;

        // for (int i = 0; i < n; i++) {
        //     if (!visited[i]) {
        //         bfs(adj, visited, count, i, q,graph);
        //     }
        // }
         bfs(adj, visited, count, 0, q,graph);
        return count;
    }
};

