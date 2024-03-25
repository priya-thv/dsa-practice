class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto t:nums){
            mp[t]++;
        }
        for(auto t:mp){
            if(t.second>1){
                ans.push_back(t.first);
            }
        }
        return ans;
    }
};
