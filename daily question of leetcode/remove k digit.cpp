class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()){
            return "0";
        }
        vector<char>v;
        for(int i=0;i<num.size();i++){
            while(k>0 && !v.empty() && v.back()>num[i]){
                v.pop_back();
                k--;
               
            }
            v.push_back(num[i]);
        }
        while(k-->0){
            v.pop_back();
        }
        string result="";
        for(auto x:v){
            if (x == '0' && result.empty())
                continue;
            result+=x;
        }

        return result.empty()? "0":result;
    }
};
