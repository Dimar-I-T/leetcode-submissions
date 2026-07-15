class Solution {
public:
    // dimar's solution
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int DP[201][201] = {0};
        DP[0][1] = triangle[0][0];
        // maksin ujung kiri
        for (int x = 0; x < n; x++){
            DP[x][0] = 10001;
        }

        // maksin sisa segi empat
        for (int x = 0; x < n - 1; x++){
            for (int y = 2 + x; y <= n; y++){
                DP[x][y] = 10001;
            }
        }

        for (int x = 0; x < n; x++){
            for (int y = 1; y <= x + 1; y++){
                DP[x][y] = triangle[x][y - 1];
            }
        }

        int hasil = 10001;
        if (n == 1){
            hasil = triangle[0][0];
        }else{
            for (int x = 1; x < n; x++){
                for (int y = 1; y <= n; y++){
                    int t = DP[x][y];
                    DP[x][y] = min(DP[x - 1][y] + t, DP[x - 1][y - 1] + t);
                    if (x == n - 1){
                        hasil = min(hasil, DP[x][y]);
                    }
                }
            }
        }
        
        return hasil;
    }
};