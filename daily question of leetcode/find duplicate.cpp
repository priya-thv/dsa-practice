class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto t:nums){
            mp[t]++;
        }
        for(auto x:mp){
            if(x.second>1){
                return x.first;
            }
        }
        return -1;
    }
};
