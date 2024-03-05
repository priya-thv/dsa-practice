class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1){
            return 1;
        }
        int j=s.size()-1;
        int i=0;
         while (i < j) {
            if (s[i] != s[j]) {
                break;
            } 
            char c = s[i];
            while ((i <= j) && (s[i] == c)) i++;
            while ((i <= j) && (s[j] == c)) j--;
        }

        // return (j == s.size() - 1 && i == 0) ? s.size() : abs(j - i) + 1;
       if (i <= j) return (j - i + 1);
       return 0;
    }
};
