class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        vector<int>v;
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto x: mp){
            v.push_back(x.first);
        }int count=0;
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            if(i>0){
                count=count+(mp[v[i]]*i);
            }
        }
        return count;
    }
};
