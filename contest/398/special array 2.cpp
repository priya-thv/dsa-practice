class Solution {
public:
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        map<int,bool>mp;
        for(int i=0;i<nums.size()-1;i++){
            int t=(1&nums[i]);
            int x=(1&nums[i+1]);
            if(t==x){
                mp[i]=false;
            }
        }
        vector<bool>v(q.size(),false);
        for(int i=0;i<q.size();i++){
            int u=q[i][0];
            int v1=q[i][1];
//             now i want to find is there any index between two index exist in map like in between to to 100 doe any number exist in map
            auto lowerIt = mp.lower_bound(u);
            auto upperIt = mp.upper_bound(v1 - 1); 
            if (lowerIt != upperIt && lowerIt != mp.end()) {
                v[i] = false;
            }else{
                v[i]=true;
            }
        }
        return v;
    }
};
