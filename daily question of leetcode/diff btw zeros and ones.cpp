class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>v(m, vector<int>(n, 0));
        vector<int>onesrow(m,0);
        vector<int>onescol(n,0);
        vector<int>zerorow(m,0);
        vector<int>zerocol(n,0);
        
        int row=0;
        int col=0;
        int z=0;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    onesrow[i]++;
                }else if(grid[i][j]==0){
                     zerorow[i]++;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    onescol[j]++;
                } else if (grid[i][j] == 0) {
                    zerocol[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                v[i][j]+=onesrow[i]-zerorow[i]+onescol[j]-zerocol[j];
            }
        }
        return v;
    }
};
