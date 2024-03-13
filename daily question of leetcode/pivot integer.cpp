class Solution {
public:
    int pivotInteger(int n) {
        if(n==1){
            return 1;
        }
        vector<int>ps(n+1,0);
        vector<int>ss(n+1,0);
        ps[0]=0;
        ss[n]=n;
        ss[0]=0;
        for(int i=1;i<=n;i++){
          ps[i]=ps[i-1]+i;
        }

        for(int j=n-1;j>=1;j--){
            ss[j]=ss[j+1]+j;
        }

        for(int i=1;i<n;i++){
            if(ps[i]==ss[i]){
                return i;
            }
        }
        return -1;
    }
};
