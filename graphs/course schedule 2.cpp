class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>indegree(n);
        unordered_map<int,list<int>>adj;
        for(int i=0;i<p.size();i++){
            int u=p[i][0];
            int v=p[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>v;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            v.push_back(front);
            for(auto t:adj[front]){
                indegree[t]--;
                if(indegree[t]==0){
                    q.push(t);
                }
            }
        }
        if(v.size()!=n){
            v.clear();
        }
        return v;
    }
};
