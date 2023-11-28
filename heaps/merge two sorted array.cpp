class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for (int i = 0; i < m; ++i) {
            pq.push(nums1[i]);
        }

        // Push elements of nums2 into the min-heap
        for (int i = 0; i < n; ++i) {
            pq.push(nums2[i]);
        }

        // Pop elements from the min-heap and place them back in nums1
        for (int i = 0; i < m + n; ++i) {
            nums1[i] = pq.top();
            pq.pop();
        }

    }
};
