class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int count=0;
        long long n=happiness.size()-1;
        long long total=0;
        for(int i=happiness.size()-1;i>=0;i--){
            
            if(count==k){
                break;
            }else if(count<k){
                int t=n-i;
                if(happiness[i]-t<0){
                    break;
                }
                total+=happiness[i]-t;
            }
            count++;
        }
        return total;
    }
};
