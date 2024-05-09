class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end());
        long long sum=0;
        int i=0,j=h.size()-1;
        while(j>=0){
            if(i<k){
                if((h[j]-i)>0){
                    sum+=(h[j]-i);
                }
            }else{
                break;
            }
            i++;
            j--;
        }
        return sum;
    }
};
