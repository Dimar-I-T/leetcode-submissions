class Solution {
public:
    // dimar's solution
    bool udah[101][101] = {0};
    vector<int> hasil;
    int n = 0, m = 0;
    int mat[101][101] = {0};
    void Spiral(int a){
        int l = 0, p = 0;
        if (!udah[a][a]){
            return;
        }

        // atas kiri -> kanan
        for (int x = a; x < m; x++){
            if (!udah[a][x]){
                break;
            }

            l = x;
            cout << "1 " << mat[a][x] << " ";
            hasil.push_back(mat[a][x]);
            udah[a][x] = 0;
        }

        cout << "\n";
        // kanan atas -> bawah
        for (int x = a + 1; x < n; x++){
            if (!udah[x][l]){
                break;
            }

            p = x;
            hasil.push_back(mat[x][l]);
            cout << "2 " << mat[x][l] << " ";
            udah[x][l] = 0;
        }

        cout << "\n";
        // bawah kanan -> kiri
        for (int x = l - 1; x >= 0; x--){
            if (!udah[p][x]){
                break;
            }

            l = x;
            hasil.push_back(mat[p][x]);
            cout << "3 "<< mat[p][x] << " ";
            udah[p][x] = 0;
        }

        cout << "\n";
        // kiri bawah -> atas
        for (int x = p - 1; x >= 0; x--){
            if (!udah[x][l]){
                break;
            }

            hasil.push_back(mat[x][l]);
            cout << "4 " << mat[x][l] << "\n";
            udah[x][l] = 0;
        }

        Spiral(a + 1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                mat[x][y] = matrix[x][y];
                udah[x][y] = 1;
            }
        }

        Spiral(0);
        for (int x = 0; x < hasil.size(); x++){
            cout << hasil[x] << " ";
        }

        return hasil;
    }
};