class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int element=0;
        unordered_map<int,int>mp;
        for(auto t:nums){
            mp[t]++;
        }
        for(int i=1;i<=mp.size();i++){
            if(mp[i]==0){
                element=i;
                break;
            }
        }
        if(element==0){
            return mp.size()+1;
        }
        return element;
    }
};
