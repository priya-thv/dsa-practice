class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums2.size();i++){
            for(int j=0;j<nums1.size();j++){
                if(nums2[i]==nums1[j]){
                    v.push_back(nums2[i]);
                }
            }
        }
        map<int,int>mp;
        for(auto t:v){
            mp[t]++;
        }
        v.clear();
        for(auto t:mp){
            v.push_back(t.first);
        }
        return v;
    }
};
