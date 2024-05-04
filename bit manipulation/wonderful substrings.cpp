class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int>v(1024,0);
        v[0]=1;
        int mask=0;
        long long result=0;
        for(auto c:word){
            int idx=c-'a';
            mask=mask^(1<<idx);
            result+=v[mask];
            for(int i=0;i<10;i++){
                int newmask=mask^(1<<i);
                result+=v[newmask];
            }
            v[mask]++;
        }
        return result;
    }
};
