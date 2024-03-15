class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int t=0;
        for(int i=0;i<apple.size();i++){
            t+=apple[i];
        }
        sort(capacity.begin(),capacity.end());
        int count=0;
        for(int i=capacity.size()-1;i>=0;i--){
            if(t-capacity[i]<=0){
                count++;
                break;
            }else{
                t=t-capacity[i];
                count++;
                
            }
        }
        return count;
    }
};
