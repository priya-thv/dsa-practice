#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        if(s.size() <= 1) {
            return s;
        }
        stack<char> st;
        st.push(s[0]);
        int i = 1;
        while(i < s.size()) {
            if (!st.empty() && s[i]!=st.top() && (s[i] == tolower(st.top()))) {
                st.pop();
            }
            else if(!st.empty() && s[i]!=st.top() && (s[i] == toupper(st.top()))){
                st.pop();
            } else {
                st.push(s[i]);
            }
            i++;
        }
        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
