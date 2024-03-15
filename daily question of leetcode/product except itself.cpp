class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(nums.size(),0);
        int count=0,s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
                s=i;
            }
        }
        int t=1;
        if(count>1){
            return ans;
        }
        
        else if(count==1){
            for(int i=0;i<n;i++){
                if(i!=s)
                t=t*nums[i];
            }
            ans[s]+=t;
            return ans;
        }else{

            for(int i=0;i<n;i++){
              t*=nums[i];
            }
            for(int i=0;i<n;i++){
                ans[i]+=t/nums[i];
            }
        }
        return ans;
    }
};
