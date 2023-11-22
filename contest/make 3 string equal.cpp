class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int a=s1.size();
        int b=s2.size();
        int c=s3.size();
        int x=min(a,(min(b,c)));
        int count=0;        
        for(int i=0;i<x;i++){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
               
                count++;
                
            }else break;
        }
        if(count==0){
            return -1;
        }
        return a+b+c-(3*count);
    }
};
