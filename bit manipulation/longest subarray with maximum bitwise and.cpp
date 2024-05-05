class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int d=*max_element(nums.begin(),nums.end());
        int s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==d){
                s++;
                maxi=max(maxi,s);
            }else{
                s=0;
            }
        }
        return maxi;
    }
};
