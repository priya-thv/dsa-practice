#define ll long long 
ll bitSum[53];

class Solution {
public:
    void solve(ll n){
        if(n<=0){
            return;
        }

        if(n==1){
            bitSum[0]++;
            return;
        }
        if(n==2){
            bitSum[0]++;
            bitSum[1]++;
            return ;
        }

        ll msb=log2(n);
        ll cn=(ll)1<<msb;
        bitSum[msb]+=(n-cn+1);
        for(int i=0;i<msb;i++){
            bitSum[i]+=cn/2;
        }
        n=n-cn;
        solve(n);
    }
    long long findMaximumNumber(long long k, int x) {
        ll l=0,r=1e15,ans=0;
        while(l<=r){
            ll mid=(l+r)/2;
            memset(bitSum,0,sizeof(bitSum));
            solve(mid);

            ll fans=0;
            for(int i=0;i<53;i++){
                if((i+1)%x==0){
                    fans+=bitSum[i];
                }
            }
            if(fans<=k){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};
