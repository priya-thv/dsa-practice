class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto x:gifts){
            pq.push(x);
        }
        long long sum =0;
        int count=1;
        while(count<=k){
            int t=floor(sqrt(pq.top()));
            pq.pop();
            pq.push(t);
            count++; 
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        
        return sum;
    }
};
