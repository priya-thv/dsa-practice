class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        priority_queue<int,vector<int>>pq;
        for(auto x:nums){
            pq.push(x);
        }
        vector<int>a;
        
        for(int i=0;i<2;i++){
            a.push_back(pq.top());
            pq.pop();
        }
        priority_queue<int,vector<int>,greater<int>>pq1;
        for(auto x:nums){
            pq1.push(x);
        }

        for(int i=0;i<2;i++){
            a.push_back(pq1.top());
             pq1.pop();
        }
        int b=(a[0]*a[1])-(a[2]*a[3]);
        return b;
    }
};
