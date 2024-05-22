class Solution {
public:
    bool ispalindrome(int start,int end,const string& s){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void dfs(int i,string& s,vector<string>&path,vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(path);
        }
        for(int end=i;end<s.size();end++){
            if(ispalindrome(i,end,s)){
                path.push_back(s.substr(i,end-i+1));
                dfs(end+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        if(s.empty()){
            return ans;
        }
        vector<string>path;
        dfs(0,s,path,ans);
        return ans;
    }
};
