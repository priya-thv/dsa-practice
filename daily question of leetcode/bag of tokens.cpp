#include <vector>
#include <algorithm>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        if(tokens.size()==1 && power<tokens[0]){
            return 0;
        }
        int count=0,c=0;
        std::sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if(tokens[i] <= power) {
                power -= tokens[i];
                count++;
                i++;
                 c=max(c,count);
            }
            else if(count>0) {
                power += tokens[j];
                count--;
                j--;
                
            }
            else {
                break;
            }
        }
        return c;
    }
};
