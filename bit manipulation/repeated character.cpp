class Solution {
public:
    char repeatedCharacter(string s) {
        int c=0;
        char t;
        for(int i=0;i<s.size();i++){
            int val=1<<(s[i]-'a');
            if((c&val)>0){
                t=s[i];
                break;
            }else{
                c|=val;
            }
        }
        return t;
    }
};
