class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int c=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]<nums[j] && nums[k]<nums[j]){
                        int sum=nums[i]+nums[j]+nums[k];
                        if(sum<c){
                            c=sum;
                        }
                    }
                }
            }
        }
        if(c==INT_MAX){
           return -1;
        }
        return c;
    
    }
};
