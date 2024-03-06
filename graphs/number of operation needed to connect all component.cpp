class Solution {
public:
    void dfs(vector<bool>&visited,unordered_map<int,list<int>>&adj,int i,int &e){
        visited[i]=true;
        for(auto n:adj[i]){
            e++;
            if(!visited[n]){
                dfs(visited,adj,n,e);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adj;
        int m=connections.size();
        for(int i=0;i<m;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0,e=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited,adj,i,e);
                count++;
            }
        }
        
        if(e/2<n-1){
            return -1;
        }
        return count-1;
    }
};
