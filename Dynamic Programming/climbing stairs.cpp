// method 1
class Solution {
public:
    int climbStairs(int n) {
        int preve=1;
        int curr=1;
        for(int i=2;i<=n;i++){
            int temp=preve+curr;
            preve=curr;
            curr=temp;
        }
        return curr;
    }
};

// method 2
class Solution {
public:
     map<int,int>mp;
    int solve(int n){
        if(n==0 || n==1){
            return 1;
        }
         if(mp.find(n)==mp.end()){
            mp[n]=solve(n-1)+solve(n-2);
         }
         return mp[n];
    }
    int climbStairs(int n) {
        return solve(n);
    }
};

// method3
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        dp[0]=1;
        for(int i=2;i<=n;i++){
            dp[i]+=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
// method 4

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
