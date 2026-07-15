class Solution {
public:
    // dimar's solution
    int uniquePaths(int m, int n) {
        int DP[101][101] = {0};
        DP[1][1] = 1;
        for (int x = 1; x <= m; x++){
            for (int y = 1; y <= n; y++){
                DP[x][y] = max(DP[x][y], DP[x - 1][y] + DP[x][y - 1]);
            }
        }

        return DP[m][n];
    }
};