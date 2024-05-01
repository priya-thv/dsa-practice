class Solution {
public:
    // long long oroperation(vector<int>&arr){
    //     long long c=0;
    //     for(int i=0;i<arr.size();i++){
    //         c|=arr[i];
    //     }
    //     return c;
    // }
    long long power(int k){
        int c=1;
        while(k>0){
            c*=2;
            k--;
        }
        return c;
    }
    long long maximumOr(vector<int>& nums, int k) {
        long long maxs=0;
        vector<int>p(nums.size());
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            p[i]=nums[i]|p[i-1];
        }
        vector<int>s(nums.size());
        s[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            s[i]=nums[i]|s[i+1];
        }
        long long n=nums[0]*power(k);
        for(int i=1;i<nums.size();i++){
            n|=nums[i];
        }
        maxs=max(maxs,n);
        long long m=nums[nums.size()-1]*power(k);
        for(int i=0;i<nums.size()-1;i++){
            m|=nums[i];
        }
        maxs=max(maxs,m);
        for(int i=1;i<nums.size()-1;i++){
            long long c=nums[i]*power(k);
            c=s[i+1] | p[i-1] |c;
            maxs=max(c,maxs);
        }
        return maxs;
    }
};

