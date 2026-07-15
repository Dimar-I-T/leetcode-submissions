class Solution {
public:
    // dimar's solution
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int DP[101][101] = {0};
        if (obstacleGrid[0][0] == 1){
            return 0;
        }
        
        DP[1][1] = 1;
        for (int x = 1; x <= n; x++){
            for (int y = 1; y <= m; y++){
                if (obstacleGrid[x - 1][y - 1] == 0){
                    DP[x][y] = max(DP[x][y], DP[x - 1][y] + DP[x][y - 1]);
                }
            }
        }

        return DP[n][m];
    }
};