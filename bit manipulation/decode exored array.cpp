class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>a;
        a.push_back(first);

        for(int i=0;i<encoded.size();i++){
            int temp=first^encoded[i];
            first=temp;
            a.push_back(first);
        }
        return a;
    }
};
