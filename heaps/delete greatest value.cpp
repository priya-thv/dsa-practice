class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        map<int,priority_queue<int,vector<int>>>mp;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[i].push(grid[i][j]);
            }
        }
        int sum=0;
        for(int i=0;i<grid[0].size();i++){
            int maxval=-1;
            for(int j=0;j<grid.size();j++){
                int temp=mp[j].top();
                mp[j].pop();
                maxval=max(temp,maxval);
            }
            sum=sum+maxval;
        }
        return sum;
  
    }
};
