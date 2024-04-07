class Solution {
public:
    bool checkValidString(string s) {
        stack<char>left;
        stack<char>astric;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left.push(i);
            }else if(s[i]=='*'){
                astric.push(i);
            }else if(s[i]==')'){
                if(!left.empty()){
                    left.pop();
                }else if(!astric.empty()){
                    astric.pop();
                }else{
                    return false;
                }
            }
        }
        while(!left.empty() && !astric.empty()){
            if (left.top() < astric.top()) {
                left.pop();
                astric.pop();
            }
            else{
                break;
            }
        }

        return left.empty();
    }
};
