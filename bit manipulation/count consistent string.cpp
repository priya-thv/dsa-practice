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


// bit manipulation

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        int flag=0;
        for(int i=0;i<allowed.size();i++){
            int val=allowed[i]-'a';
            flag=flag | (1<<val);
        }
        for(int i=0;i<words.size();i++){
            bool t=true;
            for(int j=0;j<words[i].size();j++){
                int val=words[i][j]-'a';
                if((flag & (1<<val))){
                    cout<<(flag & (1<<val))<<endl;
                    continue;
                }else{
                    t=false;
                    break;
                }
            }
            if(t==true){
                res++;
            }

        }
        return res;
    }
};
