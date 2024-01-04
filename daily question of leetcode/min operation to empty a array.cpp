class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int b=0;
        for(auto x:mp){
            if(x.second%2==0 && x.second>1 &&  x.second<5){
                b+=x.second/2;
            }else if(x.second%3==1 && x.second>1 ){
                int c;
                c=x.second-4;
                b+=c/3;
                b+=2;
            }else if(x.second%3==2 && x.second>1){
                int d;
                d=x.second-2;
                b+=d/3;
                b+=1;
            }
            else if(x.second%3==0 && x.second>1){
                b+=x.second/3;
            }else if(x.second==1)return -1;
        }
        return b;
    }
};
