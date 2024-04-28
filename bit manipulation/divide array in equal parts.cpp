class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int ,int>mp;
        for(auto t:nums){
            mp[t]++;
        }
        for(auto t:mp){
            if(t.second&1==1){
                return false;
            }
        }
        return true;
    }
};
