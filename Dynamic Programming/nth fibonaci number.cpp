// using recersion+memoization
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& dp) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fib(n, dp) << endl;
    return 0;
}


//  using tabulation


#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n]<<endl;
}


// space  optimization


#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;
        // vector<int>dp(n+1);
        int preve=0;
       int p=1;
       int t=-1;
        for(int i=2;i<=n;i++){
                t=preve+p  ;
                preve=p;
                p=t;
        }
        cout<<p<<endl;
}
