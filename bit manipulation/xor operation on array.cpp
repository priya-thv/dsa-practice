class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>a;
        a.push_back(start);
        for(int i=1;i<n;i++){
            a.push_back(start+2*i);
        }
        int result=0;
        for(auto x:a){
            result^=x;
        }
        return result;
    }
};
