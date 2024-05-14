class Solution {
public:
    int check(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        // Check if out of bounds or cell already visited
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        
        // Mark cell as visited
        visited[i][j] = true;
        
        // Explore all four directions
        int left = check(i, j - 1, grid, visited);
        int right = check(i, j + 1, grid, visited);
        int up = check(i - 1, j, grid, visited);
        int down = check(i + 1, j, grid, visited);
        
        // Unmark cell as visited (backtrack)
        visited[i][j] = false;
        
        // Return the maximum amount of gold that can be collected from this cell
        return grid[i][j] + max({left, right, up, down});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxi = 0;
        
        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, check(i, j, grid, visited));
            }
        }
        
        return maxi;
    }
};
