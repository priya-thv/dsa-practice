class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int l=0;
        int r=0;
        int ans=0;
        int maxi=0;
        while(r<nums.size()){
            if(nums[r]==1 && r!=nums.size()-1){
                mp[nums[r]]++;
            }else if(nums[r]==0 ){
                maxi=max(maxi,mp[1]);
                mp[1]=0;
            }else if(r==nums.size()-1 && nums[r]==1){
                mp[nums[r]]++;
                maxi=max(maxi,mp[1]);
            }
            r++;
        }
        return maxi;
    }
};
