class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto c:nums){
            mp[c]++;
        }
        int maxfrequency=0;
        for(auto c:mp){
            if(c.second>maxfrequency){
                maxfrequency=c.second;
            }
        }
        int count=0;
        for(auto t:mp){
            if(t.second==maxfrequency){
               count++;
            }
        }
        return count*maxfrequency;
    }
};
