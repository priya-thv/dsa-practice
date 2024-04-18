class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int& perimeter) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j])
            return;

        vis[i][j] = true;

        perimeter += (i == 0 || grid[i - 1][j] == 0) ? 1 : 0;
        perimeter += (i == grid.size() - 1 || grid[i + 1][j] == 0) ? 1 : 0;
        perimeter += (j == 0 || grid[i][j - 1] == 0) ? 1 : 0;
        perimeter += (j == grid[0].size() - 1 || grid[i][j + 1] == 0) ? 1 : 0;

        dfs(grid, i - 1, j, vis, perimeter);
        dfs(grid, i + 1, j, vis, perimeter);
        dfs(grid, i, j - 1, vis, perimeter);
        dfs(grid, i, j + 1, vis, perimeter);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, vis, perimeter);
                    // Assuming there is only one island.
                    return perimeter;
                }
            }
        }
       
        return perimeter;
    }
};
