class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n);
        vector<int>ps(n),ss(n);
        ps[0]=nums[0];
        ss[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
            ps[i]=ps[i-1]+nums[i];
            ss[n-i-1]=nums[n-i-1]+ss[n-i];
        }
        for(int i=0;i<nums.size();i++){
            int c=((nums[i]*i)-ps[i])+(ss[i]-(nums[i]*(n-i-1)));
            a[i]=c;;
        }
        return a;
    }
};
