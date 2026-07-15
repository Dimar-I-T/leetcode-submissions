class Solution {
public:
    // dimar's solution
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int DP[302][302] = {0};
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                DP[x][y] = matrix[x][y] - '0';
            }
        }

        int hasil = DP[0][0];
        for (int x = 0; x < n - 1; x++){
            for (int y = 0; y < m - 1; y++){
                int minn = min(DP[x][y], min(DP[x][y + 1], DP[x + 1][y]));
                if (DP[x + 1][y + 1] == 1){
                    DP[x + 1][y + 1] = (sqrt(minn) + 1)*(sqrt(minn) + 1);
                }
            }
        }

        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                hasil = max(hasil, DP[x][y]);
            }
        }

        // for (int x = 0; x < n; x++){
        //     for (int y = 0; y < m; y++){
        //         cout << DP[x][y] << " ";
        //     }

        //     cout << "\n";
        // }

        return hasil;
    }
};