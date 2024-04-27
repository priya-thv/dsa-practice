class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>v(26);
        for(int i=0;i<word.size();i++){
            int c=(int)word[i];
            if(c>=97){
               int t=abs(97-c);
               v[t]=word[i];
            }
        }
        set<char>st;
        int count=0;
        for(int i=0;i<word.size();i++){
            int t=(int)word[i];
            if(t<91 && (st.find(word[i])==st.end())){
                int s=abs(65-t);
                if(v[s]==tolower(word[i])){
                   count++;
                }
                st.insert(word[i]);
            }
        }
        return count;

    }
};
