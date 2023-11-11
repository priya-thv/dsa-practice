class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int tp=0;
        int r=0;
        for(auto i:mp){

            tp=tp+(i.second/2);
           
            r=r+(i.second%2);
        }
        vector<int>m;
        m.push_back(tp);
        m.push_back(r);
        return m;
    }
};
