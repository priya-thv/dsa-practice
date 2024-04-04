class Solution {
public:
    int count(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int countOdd = 0;
        int countSubarrays = 0;

        while (r < nums.size()) {
            if (nums[r] % 2 == 1) { // If the current element is odd, increment countOdd
                countOdd++;
            }
            
            while (countOdd > k && l <= r) { // Shrink the window from the left until countOdd <= k
                if (nums[l] % 2 == 1) {
                    countOdd--;
                }
                l++;
            }

            // Each valid subarray ends at index r and starts at some index in the range [l, r]
            countSubarrays += r - l + 1;
            r++;
        }

        return countSubarrays;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int u = count(nums, k);
        int v = count(nums, k - 1);
        return u - v;
    }
};
