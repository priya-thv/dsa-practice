class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        int count=0;
        int n=INT_MAX;
        for(auto t:nums){
            if((t^k)>t){
                sum+=t^k;
                n=min(n,(t^k)-t);
                count++;
            }else{
                sum+=t;
                n=min(n,t-(t^k));
            }
        }
        if(count%2==1)return sum-n;
        

        return sum; 
    }
};
