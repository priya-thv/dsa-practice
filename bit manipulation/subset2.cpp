class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> v;
        int m=(1<<nums.size());
        for(int i=0;i<m;i++){
            vector<int>d;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    d.push_back(nums[j]);
                }
            }
            v.insert(d);
        }
        return vector<vector<int>>(v.begin(),v.end());
    }
};

