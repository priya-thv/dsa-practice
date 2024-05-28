class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bit[31]={0};
        int l=0;
        int ans=0;
        for(int r=0;r<nums.size();r++){
            bool flag=false;
            for(int k=0;k<31;k++){
                if(nums[r] & (1<<k)){
                    bit[k]++;
                    if(bit[k]>1){
                        flag=true;
                    }
                }
            }
            if(flag){
                while(l<=r){
                    bool f=false;
                    for(int i=0;i<31;i++){
                        if (nums[l] & (1 << i)) {
                            bit[i]--;
                        }
                    }
                    l++;
                    for(int i=0;i<31;i++){
                        if(bit[i]>1){
                            f=true;
                            break;
                        }
                    }
                    if(!f)break;
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
