class Solution {
public:
    string customSortString(string order, string s) {
        string result="";
        unordered_map<int,int>mp;
        for(auto t:s){
            mp[t]++;
        }
        for(int i=0;i<order.size();i++){
            if(mp[order[i]]>0){
                while(mp[order[i]]!=0){
                    result.push_back(order[i]);
                    mp[order[i]]--;
                }
            }
        }
        for(auto x:mp){
            if(x.second>0){
                while(x.second!=0){
                    result.push_back(x.first);
                    x.second--;
                }
            }
        }
        return result;
    }
};
