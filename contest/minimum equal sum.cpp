class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                count1++;
            } else {
                sum1 += nums1[i];
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0) {
                count2++;
            } else {
                sum2 += nums2[i];
            }
        }

        // Adjust sums based on counts
        sum1 += count1;
        sum2 += count2;
        if(sum1==sum2){
            return sum1;
        }
        if(sum1>sum2){
            if(count2>0){
                return sum1;
            }else return -1;
        }else{
            if(count1>0){
                return sum2;
            }else return -1;
        }
        return -1;
    }
};
