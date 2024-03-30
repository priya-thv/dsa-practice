class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sub=subarray(nums,k);
        int rsub=subarray(nums,k-1);
        return (sub-rsub);
    }
    int subarray(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int left=0,right=0,ans=0;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};
