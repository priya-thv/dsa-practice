class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());

        vector<int>result(deck.size(),0);
        queue<int>q;
        for(int i=0;i<deck.size();i++){
            result[i]=i;
        }
        int i=0;

        while(i<deck.size()){
            q.push(result[i]);
            i++;
        }
        i=0;
        int j=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(i%2==0){
                result[front]=deck[j];
                j++;
            }else{
                q.push(front);
            }
            i++;
        }
        return result;
    }
};
