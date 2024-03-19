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
        int gaplen=n-(count-1);
        int availableslot=gaps*gaplen;
        int availtask=tasks.size()-maxf*count;
        int idles=max(0,availableslot-availtask);
        return tasks.size()+idles;
    }
};
