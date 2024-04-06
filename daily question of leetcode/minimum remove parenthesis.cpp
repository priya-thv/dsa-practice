class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                continue;
            }else if(s[i]=='('){
                st.push({'(',i});
            }else if(!st.empty() && s[i]==')' && st.top().first=='('){
                st.pop();
            }
            else{
                st.push({')',i});
            }
        }
        set<int>c;
        while(!st.empty()){
            c.insert(st.top().second);
            st.pop();
        }
        string result="";
        for(int i=0;i<s.size();i++){
            if(c.find(i)!=c.end()){
                continue;
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
