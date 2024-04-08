class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& p) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<p.size();i++){
            int u=p[i][0];
            int v=p[i][1];
            adj[u].push_back(v);
        }
        int size=0;
        queue<int>q;
        vector<int>indegree(nc,0);
        for(int i=0;i<p.size();i++){
            indegree[p[i][1]]++;
        }
        for(int i=0;i<nc;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            size++;
            for(auto x:adj[top]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(size==nc){
            return true;
        }

        return false;
    }
};
