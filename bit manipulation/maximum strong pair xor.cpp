class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxresult=0;
        int left=0;
        for(int i=0;i<nums.size();i++){
            left=i;
            while(left<nums.size() && abs(nums[i]-nums[left])<=min(nums[i],nums[left])){
                maxresult=max(maxresult,(nums[i]^nums[left]));
                left++;
            }
            
        }
        return maxresult;
    }
};
