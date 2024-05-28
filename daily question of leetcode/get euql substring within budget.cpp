class Solution {
public:
    int equalSubstring(string s, string t, int mc) {
        int left=0;
        int right=0;
        int maxi=0;
        while(right<s.size()){
            int x=abs(s[right] - t[right]);
            if(mc>=x){
                mc-=x;
                right++;
            }
            else{
                int c=abs(s[left] - t[left]);
                mc+=c;
                left++;
            }
            maxi = max(maxi, right - left); 
        }
        return maxi;
    }
};
