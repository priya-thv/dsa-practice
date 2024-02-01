class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>a;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=3){
            if(nums[i+2]-nums[i+1]>k || nums[i+1]-nums[i]>k || nums[i+2]-nums[i]>k){
                a.clear();
                return a;
            }else{
                vector<int>c;
                c.push_back(nums[i]);
                c.push_back(nums[i+1]);
                c.push_back(nums[i+2]);
                a.push_back(c);
            }
        }
        return a;
    }
};
