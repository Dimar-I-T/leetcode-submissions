class Solution {
public:
    // dimar's solution
    vector<int> tetangga[90001];
    bool pernah[90001] = {0};

    void DFS(int di){
        if (!pernah[di]){
            pernah[di] = true;
            //cout << "DFS" <<di <<"=" << pernah[di] << "\n";
            for (int x = 0; x < tetangga[di].size(); x++){
                DFS(tetangga[di][x]);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mat[305][305] = {0};
        int a = 1;
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if (grid[x][y] == '1'){
                    mat[x + 1][y + 1] = a;
                    a++;
                }
            }
        }

        int tx[] = {1, -1, 0, 0};
        int ty[] = {0, 0, 1, -1};
        for (int x = 1; x <= n; x++){
            for (int y = 1; y <= m; y++){
                for (int z = 0; z < 4; z++){
                    int xS = x + tx[z], yS = y + ty[z];
                    if (mat[x][y] != 0 && mat[xS][yS] != 0){
                        //cout << mat[x][y] << "->" << mat[xS][yS] << "\n";
                        tetangga[mat[x][y]].push_back(mat[xS][yS]);
                    }
                }
            }
        }

        int hasil = 0;
        //cout << a;
        for (int x = 1; x < a; x++){
            if (!pernah[x] && x != 0){
                //cout << x << "belum 1" << "\n";
                DFS(x);
                hasil++;
            }
        }

        return hasil;
    }
};