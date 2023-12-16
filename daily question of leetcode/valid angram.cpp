class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        else if(s.size()==0 && t.size()!=0){
            return false;
        }
        else if(s.size()!=0 && t.size()==0){
            return false;
        }
        map<char,int>mp;
        map<char,int>mp1;
        for(auto a:s){
            mp[a]++;
        }
        for(auto a:t){
            mp1[a]++;
        }
        for(int i=0;i<t.size();i++){
            if(mp1[t[i]]!=mp[t[i]] ){
                return false;
            }
        }
        return true;
    }
};
