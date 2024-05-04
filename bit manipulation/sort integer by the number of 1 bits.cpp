class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,list<int>>mp;
        for(auto t:arr){
            int v=__builtin_popcount(t);
            mp[v].push_back(t);
        }
        vector<int>v;
       
        for(auto t:mp){
            vector<int> temp(t.second.begin(), t.second.end());
            sort(temp.begin(), temp.end());
            for (auto j : temp) {
                v.push_back(j);
            }
        }
        return v;
    }
};


OR

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(auto t:arr){
            int v=__builtin_popcount(t);
            mp[v].push_back(t);
        }
        vector<int>v;
       
        for(auto t:mp){
            sort(t.second.begin(), t.second.end());
            for (auto j : t.second) {
                v.push_back(j);
            }
        }
        return v;
    }
};
