class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        map<int,int>mp1;
        cout<<matches[0].size();
        vector<vector<int>>answer;
       
        for (int i = 0; i < matches.size(); i++) {
            mp[matches[i][0]]++;
            mp1[matches[i][1]]++;
        }
        vector<int>winners;
        for(auto x:mp){
            if(mp1[x.first]==0){
                winners.push_back(x.first);
            }
        }
        vector<int>loser;
       for (auto x : mp1) {
            if (x.second == 1) {
                loser.push_back(x.first);
            }
        }
        answer.push_back(winners);
        answer.push_back(loser);
        return answer;
    }
};
