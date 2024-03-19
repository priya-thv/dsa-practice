class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;

        for(auto t:tasks){
            mp[t]++;
        }
        int maxf=0;
        int count=0;
        for(auto t:mp){
            if(t.second>maxf){
                maxf=t.second;
            }
        }
        for(auto t:mp){
            if(t.second==maxf){
               count++;
            }
        }
        int gaps=maxf-1;
        int gapslen=n;
        int availslots=n*gaps;
        int availtask=tasks.size()-maxf*count;
        int idealslots=n*gaps-((count-1)*gaps);
        int idel=max(0,idealslots-availtask);
        return tasks.size()+idel;
    }
};
