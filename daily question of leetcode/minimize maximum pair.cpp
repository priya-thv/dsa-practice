class Solution {
public:
   
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
      
       int mm=0;
       for(int i=0;i<n;i++){
           int b=nums[i]+nums[n-1];
           if(mm<b){
               mm=b;
           }
           n--;
       }
       return mm;
    }
};
