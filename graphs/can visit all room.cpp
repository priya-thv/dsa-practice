class Solution {
public:
    void dfs(unordered_map<int,list<int>>&adj,int node,vector<bool>&visited,int &count){
        
        visited[node]=true;
        for(auto t:adj[node]){
            if(!visited[t]){
                count++;
                dfs(adj,t,visited,count);
            }
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                int u=rooms[i][j];
                adj[i].push_back(u);
            }
        }
        vector<bool>visited(rooms.size(),false);
        int count=1;
        dfs(adj,0,visited,count);
        if(count!=rooms.size()){
            return false;
        }

        return true;
    }
};
