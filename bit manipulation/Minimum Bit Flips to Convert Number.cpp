class Solution {
public:
    int minBitFlips(int start, int goal) {
        // normal simple approch
        // if(start==goal){
        //     return 0;
        // }
        // int count=0;
        // for(int i=0;i<32;i++){
        //     int c=start&1;
        //     int d=goal &1;
        //     start=start>>1;
        //     goal=goal>>1;
        //     if(c!=d){
        //         count++;
        //     }
        // }
        // return count;
        //optimized
        int c=start^goal;
        return __builtin_popcount(c);
    }
};
