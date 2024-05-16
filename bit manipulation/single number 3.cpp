class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        cout<<x<<endl;
        int count=0;
        int t = x;
        while ((t & 1) == 0 && t != 0) {
            count++;
            t >>= 1;
        }
        int bitmask = 1 << count;
        int d=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&bitmask)!=0){
                d^=nums[i];
            }
        }
        cout<<d;
        vector<int>v;
        v.push_back(d);
        int b=x^d;
        v.push_back(b);
        return v;
    }
};
