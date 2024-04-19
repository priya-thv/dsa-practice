class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int lb = 0;
        int ub = nums.size()-1;
        int mid;
        int idx = -1;
        while(lb<=ub)
        {
            mid=lb+((ub-lb)/2);
            if(nums[mid]==target){
                idx=mid;break;
            }
            else if(nums[mid]<target)
            lb=mid+1;
            else
            ub=mid-1;
        }
        if(idx!=-1)
        {
            int y = idx;
            while(y>=0 && nums[y]==target)
            {
                y--;
            }
            y++;
            for(int i=y;i<nums.size();i++){
                if(nums[i]==target)
                res.push_back(i);
                else
                break;
            }
        }
        return res;
    }
};
