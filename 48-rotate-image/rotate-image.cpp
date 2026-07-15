class Solution {
public:
    // dimar's solution
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int x = n - 1; x >= 0; x--) {
            for (int y = 0; y < n; y++) {
                int hor = matrix[x][y];
                int ver = matrix[y][n - x - 1];
                matrix[x][y] = ver;
                matrix[y][n - x - 1] = hor;
            }
        }

        int i = 0;
        for (int x = 0; x < n/2; x++) {
            for (int y = i; y < n - 1 - i; y++) {
                int kiri = matrix[y][x];
                int kanan = matrix[n - y - 1][n - x - 1];
                matrix[y][x] = kanan;
                matrix[n - y - 1][n - x - 1] = kiri;
            }

            i++;
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cout << matrix[x][y] << " ";
            }

            cout << "\n";
        }
    }
};