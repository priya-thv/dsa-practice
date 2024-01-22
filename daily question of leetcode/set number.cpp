class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>a;
        int n=nums.size();
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int b;
        for(auto x:mp){
            if(x.second==2){
                a.push_back(x.first);
                b=x.first;
            }
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        int osum=n*(n+1)/2;
        a.push_back(b+(osum-sum));
        return a;
    }
};
