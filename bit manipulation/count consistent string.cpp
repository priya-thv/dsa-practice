class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        
        for(int i=0;i<words.size();i++){
            bool flag=false;
            for(int j=0;j<words[i].size();j++){
                if(allowed.find(words[i][j])== string::npos){   
                    flag=true;
                    break;
                }else{
                    continue;
                }
            }  
            if(flag==false){
                res++;
            }
        }
        return res;
    }
};
