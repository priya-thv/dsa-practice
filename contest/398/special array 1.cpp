class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            int n=(1&nums[i]);
            int t=(1&nums[i+1]);
            if(n==t){
                return false;
            }
        }
        return true;
    }
};
