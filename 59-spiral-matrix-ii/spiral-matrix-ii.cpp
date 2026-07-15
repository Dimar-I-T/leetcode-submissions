class Solution {
public:
    // dimar's solution
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> hasil(n, vector<int>(n));
        int i = 0;
        int mulai = 1;
        while (i < n) {
            for (int x = i; x < n - i; x++) {
                hasil[i][x] = mulai;
                mulai++;
            }

            mulai--;
            for (int x = i; x < n - i; x++) {
                hasil[x][n - i - 1] = mulai;
                mulai++;
            }

            mulai--;
            for (int x = n - i - 1; x >= i; x--) {
                hasil[n - i - 1][x] = mulai;
                mulai++;
            }

            mulai--;
            for (int x = n - i - 1; x >= i + 1; x--) {
                hasil[x][i] = mulai;
                mulai++;
            }

            i++;
        }

        return hasil;
    }
};