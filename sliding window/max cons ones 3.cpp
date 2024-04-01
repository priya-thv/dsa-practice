// tc=o(n) && sc=o(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxi=0,zero=0,n=nums.size();
        while(r<n){
            if(nums[r]==0) zero++;
            if(zero>k){
                if(nums[l]==0) zero--;
                    l++;
            }
            if(zero<=k){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};

// tc=o(n) && sc=o(n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l=0;
        int r=0;
        int ans=0;
        int maxi=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(nums[r]==0 && mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            ans=r-l+1;
            maxi=max(maxi,ans);
            r++;
        }
        return maxi;

    }
};


// tc=o(2n) && sc=o(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // unordered_map<int,int>mp;
        int ones=0;
        int zero=0;
        int l=0;
        int r=0;
        int ans=0;
        int maxi=0;
        while(r<nums.size()){
            // mp[nums[r]]++;
            if(nums[r]==1)ones++;
            else zero++;
            while(nums[r]==0 && zero>k){

                // mp[nums[l]]--;
                if(nums[l]==1)ones--;
                else zero--;
                l++;
            }
            ans=r-l+1;
            maxi=max(maxi,ans);
            r++;
        }
        return maxi;

    }
};
