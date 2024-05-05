class Solution {
public:
    int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>v;
        vector<int>ans(queries.size(),1);
        for(int i = 0; i < 32; i++){
            if(n & (1 << i))
                v.push_back(1 << i);
        }       
        for(int i=0;i<queries.size();i++){
            for(int s = queries[i][0]; s <= queries[i][1]; s++)
                ans[i] = ((long)ans[i] * v[s]) % mod;
        }
        return ans;
    }
};
