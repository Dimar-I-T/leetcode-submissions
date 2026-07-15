class Solution {
public:
    // dimar's solution
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int DP[105][105] = {0}, M[105][105] = {0};
        bool U[105][105] = {0};
        for (int x = 0; x < n; x++){
            DP[x][0] = 100005;
            DP[x][n + 1] = 100005;
        }

        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                DP[x][y + 1] = matrix[x][y]; 
                M[x][y + 1] = matrix[x][y];
            }
        }

        for (int x = 0; x < n - 1; x++){
            for (int y = 1; y <= n; y++){
                // kiri
                for (int z = -1; z <= 1; z++){
                    if (!U[x + 1][y - z]){
                        DP[x + 1][y - z] += DP[x][y];
                        U[x + 1][y - z] = true;
                    }else{
                        DP[x + 1][y - z] = min(DP[x + 1][y - z], M[x + 1][y - z] + DP[x][y]);
                    }
                }
            }
        }

        int hasil = 100005;
        for (int x = 1; x <= n; x++){
            hasil = min(hasil, DP[n - 1][x]);
        } 
        
        // for (int x = 0; x < n; x++){
        //     for (int y = 0; y < n + 2; y++){
        //         cout << DP[x][y] << " ";
        //     }

        //     cout << "\n";
        // }

        return hasil;
    }
};