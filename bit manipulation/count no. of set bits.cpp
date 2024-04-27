class Solution {
public:
// count no. of bits 
    int convert(int n){
        int count=0;
        while(n>0){
            count+=n&1;
            n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>v;
        v.push_back(0);
        for(int i=1;i<=n;i++){
           int s=convert(i);
           v.push_back(s);
        }
        return v;
    }
};
