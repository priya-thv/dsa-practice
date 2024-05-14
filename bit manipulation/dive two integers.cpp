class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        if (divisor == 1) {
            return dividend;
        }
        bool sign = (dividend<0 == divisor<0);
        unsigned int ans=0;
        unsigned int n=abs(dividend);
        unsigned int m=abs(divisor);
        while(n>=m){
            int count=0;
            while(n>(m<<(count+1))){
                count++;
            }
            ans+=(1<<count);
            n=n-(m<<count);
        }
        if(ans==(1<<31)&& sign==true){
            return INT_MAX;
        }
        
        return sign?ans:(-1*ans);
    }
};

