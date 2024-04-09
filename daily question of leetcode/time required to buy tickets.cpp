class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }
        int count=0;
        while(tickets[k]!=0){
            int front=q.front().first;
            int c=q.front().second;
            front=front-1;
            count++;
            q.pop();
            if(c==k && front==0){
                break;
            }else if(front>0){
                q.push({front,c});
            }
        }

        return count;
    }
};
