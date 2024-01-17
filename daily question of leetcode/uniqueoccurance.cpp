class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto x:arr){
            mp[x]++;
        }
        for(auto x:mp){
            int k=x.second;
            int t=x.first;
            for(auto y:mp){
                if(y.second==k && y.first!=t){
                    return false;
                    break;
                }
            }
        }

        return true;
    }
};
