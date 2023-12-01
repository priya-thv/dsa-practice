class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string r="";
        string b="";

        for(int i=0;i<word1.size();i++){
            r+=word1[i];
        }
        for(int i=0;i<word2.size();i++){
            b+=word2[i];
        }
        if(r.size()!=b.size())return false;
        for(int i=0;i<r.size();i++){
            if(r[i]!=b[i])
            return false;
        }

        return true;
    }
};
