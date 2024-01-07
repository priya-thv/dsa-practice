class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int t=pq.top();
            pq.pop();
            int r=pq.top();
            pq.pop();
            pq.push(t-r);
            
        }
        return pq.top();
    }
};
