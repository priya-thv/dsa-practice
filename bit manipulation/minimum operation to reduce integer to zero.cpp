class Solution {
public:
    
    
    int minOperations(int n) {
        // recursion
        // if(n==0 || n==1){
        //     return n;
        // }
        // int val=1;
        // while(val*2<n){
        //     val=val*2;
        // }

        // return 1+min(minOperations(val*2-n),minOperation(n-val))
        //bit
        // _builtin_popcout is used to count no. of set bits
        int res=0;
        for(int i=0;i<17;i++){
            if(__builtin_popcount(n+(1<<i))<__builtin_popcount(n)){
                n=n+(1<<i);
                ++res;
            }
        }
        return res+__builtin_popcount(n);
        
    }
};
