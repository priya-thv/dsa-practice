class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<int,int>mp;
        int left=0;
        int right=0;
        int ans=0;
        int count=0;
        while( right<s.size()){
            mp[s[right]]++;
            while(right-left==2){
                if(mp.size()==3){
                    ans++;
                }
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};
