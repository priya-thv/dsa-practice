class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), xor1 = 0, xor2 = 0, ans = 0;

        for(auto it : nums1) xor1 ^= it;
        for(auto it : nums2) xor2 ^= it;

        if(n1 % 2) ans ^= xor2; //if n1 is odd, all elements of nums2 should be XORed
        if(n2 % 2) ans ^= xor1; //if n2 is odd, all elements of nums1 should be XORed
        return ans;
    }
};
