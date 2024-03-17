// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>> ans;
//         if(intervals.size()==0){
//             ans.push_back(newInterval);
//             return ans;
//         }
//         if(intervals.size()==1 && newInterval[1]<intervals[0][0]){
           
//             ans.push_back(newInterval);
//              ans.push_back({intervals[0][0],intervals[0][1]});
//             return ans;
//         }
//         if(intervals.size()==1 && newInterval[0]>intervals[0][1]){
//             ans.push_back({intervals[0][0],intervals[0][1]});
//             ans.push_back(newInterval);
//             return ans;
//         }
//         int t = 0;
//         int j = 0;
//         int end = -1;
//         int start = -1;
        
//         // Find the end of the new interval
//         for (int i = 0; i < intervals.size(); i++) {
//             if (intervals[i][0] == newInterval[1]) {
//                 end = intervals[i][1];
//                 j = i;
//                 break;
//             }else if(intervals[i][0] < newInterval[1] && intervals[i][1]>= newInterval[1]){
//                 end = intervals[i][1];
//                 j = i;
//                 break;
//             } 
//             else if (intervals[i][0] > newInterval[1]) {
//                 break;
//             }
//         }
        
//         vector<int> v(2, 0);
//         if (end != -1) {
//             v[1] = end;
//         } else {
//             v[1] = newInterval[1];
//         }

//         // Find the start of the new interval
//         for (int i = 0; i < intervals.size(); i++) {
//             if (intervals[i][0] < newInterval[0] && intervals[i][1] >= newInterval[0]) {
//                 start = intervals[i][0];
//                 t = i;
//                 break;
//             } else if (intervals[i][0] > newInterval[0]) {
//                 break;
//             }
//         }
        
//         if (start != -1) {
//             v[0] = start;
//         } else {
//             v[0] = newInterval[0];
//         }
        
//         // Insert the new interval into the correct position
//         for (int i = 0; i < intervals.size(); i++) {
//             if (i < t) {
//                 ans.push_back({intervals[i][0], intervals[i][1]});
//             } else if (i == t && i != j) {
//                 continue;
//             } else if (i == j) {
//                 ans.push_back(v);
//             } else if (i > j) {
//                 ans.push_back({intervals[i][0], intervals[i][1]});
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.empty()) {
            ans.push_back(newInterval);
            return ans;
        }
        
        int n = intervals.size();
        int i = 0;
        
        // Add intervals that end before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }
        
        // Merge intervals that overlap with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        
        // Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i++]);
        }
        
        return ans;
    }
};
