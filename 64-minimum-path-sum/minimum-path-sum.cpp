class Solution {
public:
    // dimar's solution
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int x = 1; x < n; x++){
            grid[x][0] += grid[x - 1][0];
        }

        for (int x = 1; x < m; x++){
            grid[0][x] += grid[0][x - 1];
        }

        for (int x = 1; x < n; x++){
            for (int y = 1; y < m; y++){
                int t = grid[x][y];
                grid[x][y] = min(grid[x - 1][y] + t, grid[x][y - 1] + t);
            }
        }

        return grid[n - 1][m - 1];
    }
};