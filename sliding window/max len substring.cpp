class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int>mp;
        int left=0;
        int right=0;
        int ans=0;
        while(left<=right && right<s.size()){
            mp[s[right]]++;
            while(mp[s[right]]>2){
                
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
