class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            auto it=find(t.begin(),t.end(),s[i]);
            int index = distance(t.begin(), it);
            sum+=abs(i-(index));
        }
        return sum;
    }
};
