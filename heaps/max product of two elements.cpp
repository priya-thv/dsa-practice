class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>>pq;
       
        for(auto x:nums){
            pq.push(x);
        }
        int c=1;
        int t;
        for(int i=0;i<2;i++){
             t=pq.top();
            pq.pop();
             c=c*(t-1);
        }
        return c;
    }
};
