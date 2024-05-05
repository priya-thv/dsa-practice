class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>v;
        v.push_back(pref[0]);
        for(int i=1;i<pref.size();i++){
            int val=pref[i]^pref[i-1];
            v.push_back(val);
        }
        return v;
    }
};
