class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>v(code.size(),0);
        int count=0;
        if(k==0)return v;
        if(k>0){
            for(int i=0;i<code.size();i++){
                int sum=0;
                for(int j=1;j<=k;j++){
                    sum+=code[(i+j)%code.size()];
                }
                v[i]+=sum;
            }
        }
        else{
            for(int i=0;i<code.size();i++){
                int sum=0;
                for(int j=1;j<=-1*k;j++){
                    sum+=code[(i-j+code.size())%code.size()];
                }
                v[i]+=sum;
            }
        }
        return v;
    }
};
