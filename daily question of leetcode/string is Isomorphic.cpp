class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
          return false;  
        } 
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
        mp.reserve(s.size());
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() && t[mp[s[i]]]!=t[i]){
                return false;
            }
            if(mp1.find(t[i])!=mp1.end() && s[mp1[t[i]]]!=s[i]){
                return false;
            }
            mp[s[i]]=i;
            mp1[t[i]]=i;
        }
        return true;
    }
};
