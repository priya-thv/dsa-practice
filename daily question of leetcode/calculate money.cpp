class Solution {
public:
    int totalMoney(int n) {
        int b,c;
         int sum=0;
        if(n<7){
            b=n;
            sum=0;
        }else {
             b=n%7;
              c=n/7;
            sum+=c*28+7*c*(c-1)/2;
        }
       
        int d=c;
        for(int i=0;i<b;i++){
           d++;
           sum+=d;
        }
        return sum;
    }
};
