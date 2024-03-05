class Solution {
public:

    void dfs(vector<bool>&visited,int i,unordered_map<int,list<int>>&adj,int &count,int &e){
        visited[i]=true;
        count++;
        for(auto n:adj[i]){
            e++;
            if(!visited[n]){
               dfs(visited,n,adj,count,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int count=0,e=0;
                dfs(visited,i,adj,count,e);
                if( count>2 && e==count*(count-1)){
                   c++;
                }
                else if(count<=2){
                    c++;
                }
            }
        }
        return c;
    }
};
