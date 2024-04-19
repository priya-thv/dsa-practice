class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    c++;
                }
            }
            pq.push({c,i});
        }
        for(int i=0;i<k;i++){
            if(!pq.empty()){
                v.push_back(pq.top().second);
                pq.pop();
            }
        }
        return v;
    }
};
