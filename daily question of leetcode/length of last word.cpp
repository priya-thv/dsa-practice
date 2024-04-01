class Solution {
public:
    int lengthOfLastWord(string s) {
        int size=s.size();
        reverse(s.begin(),s.end());
        bool flag=false;
        int count=0;
        for(int i=0;i<s.size();i++){
            char z=s[i];
            if(z==' ' && flag==false){
                continue;
            }else if(z!=' '){
               count++;
               flag=true;
            }
            else if(z==' ' && flag==true){
                break;
            }
        }
        return count;
    }
};
