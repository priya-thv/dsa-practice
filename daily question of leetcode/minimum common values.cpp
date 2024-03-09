class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    set<int>s;
    int smallest = INT_MAX;
    for (int i = 1; i < nums1.size(); ++i) {
        if (nums1[i] == nums1[i - 1]) {
            nums1[i] = -1;
        }
    }

    for (int i = 1; i < nums2.size(); ++i) {
        if (nums2[i] == nums2[i - 1]) {
            nums2[i] = -1;
        }
    }

    for (int i = 0; i < nums1.size(); ++i) {
        if (nums1[i] != -1) {
            s.insert(nums1[i]);
        }
    }

    for (int j = 0; j < nums2.size(); ++j) {
        if (nums2[j] != -1) {
            if (s.find(nums2[j]) == s.end()) {
                s.insert(nums2[j]);
            } else {
                if (nums2[j] < smallest) {
                    smallest = nums2[j];
                }
            }
        }
    }

    if (smallest == INT_MAX) {
        return -1;
    }

    return smallest;
    }
};
