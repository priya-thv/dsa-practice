class Solution {
public:
     bool isnice(string &s){
        unordered_map<char,int>mp;
        for(auto t:s){
            mp[t]++;
        }
        for(auto t:s){
            if(mp.find(toupper(t))==mp.end() || mp.find(tolower(t))==mp.end()){
                return false;
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        string result="";
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<=s.size();j++){
                string str=s.substr(i,j-i);
                if(isnice(str) && str.size()>maxlen){
                    result=str;
                    maxlen=str.size();
                }
            }
        }
        return result;
    }

   

};
