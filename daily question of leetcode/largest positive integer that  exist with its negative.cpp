class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            if(nums[left]<0 && abs(nums[left])==nums[right]){
                return nums[right];
            }else if(abs(nums[left])<nums[right]){
                right--;
            }else if(abs(nums[left])>nums[right]){
                left++;
            }else if(nums[left]>0){
                return -1;
            }
        }
        return -1;
    }
};
