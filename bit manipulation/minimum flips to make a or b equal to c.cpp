class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        for(int i=0;i<32;i++){
            int x=a&1;
            int y=b&1;
            int z=c&1;
            if(z==0 && (x==1 && y==1)){
                count+=2;
            }else if(z==0 && ((x==1 && y==0) || (x==0 &&y==1))){
                count++;
            }else if(z==1 && (x==0 && y==0)){
                count++;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;
    }
};
