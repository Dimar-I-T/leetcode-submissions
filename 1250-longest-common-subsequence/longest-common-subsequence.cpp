class Solution {
public:
    // dimar's solution
    int longestCommonSubsequence(string text1, string text2) {
        int DP[1001][1001] = {0};
        bool Dipake[1001] = {0};
        int t1 = text1.length(), t2 = text2.length();
        for (int x = 0; x < t1; x++){
            for (int y = 0; y < t2; y++){
                if (text1[x] == text2[y]){
                    DP[x][y] = 1;
                }
            }
        }
        
        int h = 0;
        for (int x = t1 - 1; x >= 0; x--){
            for (int y = t2 - 1; y >= 0; y--){
                if (DP[x][y] == 1){
                    DP[x][y] = max(DP[x + 1][y + 1] + DP[x][y], DP[x][y + 1]);
                }else{
                    DP[x][y] = max(DP[x + 1][y], DP[x][y + 1]);
                }
            }
        }

        return DP[0][0];
    }
};