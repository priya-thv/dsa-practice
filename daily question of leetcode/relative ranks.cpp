class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> s(score.size());
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        int count = 0;
        while (!pq.empty()) {
            int topScore = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            if (count == 0) {
                s[index] = "Gold Medal";
            } else if (count == 1) {
                s[index] = "Silver Medal";
            } else if (count == 2) {
                s[index] = "Bronze Medal";
            } else {
                s[index] = to_string(count + 1);
            }
            
            count++;
        }
        return s;
    }
};
