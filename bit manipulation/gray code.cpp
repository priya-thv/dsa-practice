class Solution {
public:
    vector<int> grayCode(int n) {
        int m=(1<<n);
        vector<int>v(m);
        for(int i=0;i<m;i++){
            v[i]=i^(i>>1);
        }
        return v;
    }
};
