class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        int flag=0;
        int i=0;
        while(i<s.size()){
            int val=s[i]-'a';
            if(flag & (1<<val)){
                flag=0;
                ans++;
            }
            flag= flag | (1<<val);
            i++;
        }
        return ans;
    }
};
