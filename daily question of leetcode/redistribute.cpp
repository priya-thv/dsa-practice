class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<int,int>a;
        for(auto x:words){
            for(auto v:x){
                a[v]++;
            }
        }
        int n=words.size();
        for(auto i:a){
            if(i.second%n!=0){
                return false;
            }
        }
        return true;
    }
};
