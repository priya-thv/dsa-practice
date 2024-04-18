#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1);
    }

    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& vis) {
        if (!check(grid, x, y)) return 0;
        
        if (vis[x][y]) return 0;
        
        vis[x][y] = true;

        int perimeter = 0;

        perimeter += (x == 0 || grid[x - 1][y] == 0) ? 1 : 0;
        perimeter += (x == grid.size() - 1 || grid[x + 1][y] == 0) ? 1 : 0;
        perimeter += (y == 0 || grid[x][y - 1] == 0) ? 1 : 0;
        perimeter += (y == grid[0].size() - 1 || grid[x][y + 1] == 0) ? 1 : 0;

        perimeter += dfs(grid, x - 1, y, vis);
        perimeter += dfs(grid, x + 1, y, vis);
        perimeter += dfs(grid, x, y - 1, vis);
        perimeter += dfs(grid, x, y + 1, vis);
        
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Find the first cell of the island to start DFS
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j, vis);
                }
            }
        }

        return 0; // No island found
    }
};
