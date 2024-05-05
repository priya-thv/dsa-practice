class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c=__builtin_popcount(num2);
        int b=__builtin_popcount(num1);
        int ans=0;
        if(b==c){
            return num1;
        }
        else if(b>c){
            while(c>0){
                int a=log2(num1);
                ans+=(1<<a);
                num1-=(1<<a);
                c--;
            }
        }else{
            ans+=num1;
            c=c-b;
            int i=0;
            while(c>0){
                if((num1&(1<<i))==0){
                    c--;
                    ans+=(1<<i);
                }
                i++;
            }
        }
        return ans;
    }
};
