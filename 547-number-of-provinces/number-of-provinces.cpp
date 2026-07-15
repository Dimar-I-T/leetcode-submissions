class Solution {
public:
    // dimar's solution
    vector<int> tetangga[203];
    bool pernah[2001] = {0};
    void DFS(int di){
        if (!pernah[di]){
            pernah[di] = true;
            for (int x = 0; x < tetangga[di].size(); x++){
                DFS(tetangga[di][x]);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                if (x == y){
                    continue;
                }

                if (isConnected[x][y] == 1){
                    tetangga[x + 1].push_back(y + 1);
                }
            }
        }

        int hasil = 0;
        for (int x = 1; x <= n; x++){
            if (!pernah[x]){
                hasil++;
                DFS(x);
            }
        }

        return hasil;
    }
};