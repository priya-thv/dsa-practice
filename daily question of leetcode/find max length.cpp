class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_length = 0;
        int count = 0;

        // Initialize the map with an initial count of 0 at index -1
        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count--;
            } else {
                count++;
            }

            // Check if the count has been seen before
            if (mp.find(count) != mp.end()) {
                max_length = max(max_length, i - mp[count]);
            } else {
                // Store the count and its corresponding index
                mp[count] = i;
            }
        }

        return max_length;
    }
};
