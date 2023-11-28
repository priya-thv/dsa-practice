class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>p;
        for(int i=0;i<nums.size();i++){
            p.push_back({nums[i],i});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x:p){
            pq.push(x);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<pair<int,int>>t;
        while(!pq.empty()){
            t.push_back({pq.top().second,pq.top().first});
             pq.pop();
        }
        sort(t.begin(),t.end());
        
        vector<int>a;
        for(auto x:t){
            a.push_back(x.second);
        }
       return a;
    }
};
