class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long count = 0;
        int left = 0;
        int maxElement = *max_element(nums.begin(), nums.end());

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            if (nums[right] == maxElement) {
                while (mp[maxElement] >= k && left <= right) {
                    count += nums.size() - right; // Subarrays ending at 'right' contribute to count
                    mp[nums[left]]--; // Move left pointer
                    left++;
                }
            }
        }
        return count;
    }
};
