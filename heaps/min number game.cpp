class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int a=0,b=0;
        vector<int>t;
        for(auto a:nums){
           pq.push(a);
        }
        while(!pq.empty()){
            a+=pq.top();
            pq.pop();
            b+=pq.top();
            pq.pop();
            t.push_back(b);
            t.push_back(a);
            a=a*0;
            b=b*0;
        }
        return t;
    }
};
