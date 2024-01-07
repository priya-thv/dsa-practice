class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto a:nums){
           pq.push(a);
        }
        int count=0;
        while(!pq.empty()){
            int k=pq.top();
            pq.pop();
            if(k>0){
                nums.clear();
               while(!pq.empty()){
                   int q=pq.top();
                   pq.pop();
                   nums.push_back(q-k);
               }
               for(auto x:nums){
                   pq.push(x);
               }
               count++;
            }else{
                continue;
            }
        }
        return count;
    }
};
