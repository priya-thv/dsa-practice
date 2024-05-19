class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        int dg=0;
        int start=nums[0];
        long long dif=0;
        while(start>0){
            dg++;
            start/=10;
        }
        for(int i=0;i<dg;i++){
            map<int,int>mp;
            for(int j=0;j<n;j++){
                mp[nums[j]%10]++;
                nums[j]=nums[j]/10;
            }
            int cn=n;
            for(auto t:mp){
                cn-=t.second;
                dif+=(long long)t.second*cn;
            }
        }
        return dif;
    }
};
