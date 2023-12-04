class Solution {
public:
    string largestGoodInteger(string num) {
       
        
        map<int,int>mp;
        for(auto x: num){
            mp[x]++;
        }
        vector<int>a;
        for(int i=0;i<num.size()-2;i++){
            if(mp[num[i]]>=3 && num[i+1]==num[i] && num[i+2]==num[i]){
                a.push_back(num[i]);
            }
        }
        if(a.empty()){
            return "";
        }
         std::sort(a.begin(), a.end());
        char c = a.back();
        int d = (c - '0') * 100 + (c - '0') * 10 + (c - '0');
        
        std::string s = std::to_string(d);
        if(s=="0"){
            return "000";
        }
        return s;
    }
};
