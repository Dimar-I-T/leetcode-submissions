class Solution {
public:
    // dimar's solution
    int n = 0, m = 0;
    bool pernah[201][201] = {0};
    int mat[201][201] = {0};
    vector<pair<int, int>> flip;

    bool BFS(int x, int y){
        int tx[] = {1, -1, 0, 0}; 
        int ty[] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        bool hasil = true;
        q.push({x, y});
        while (!q.empty()){
            pair<int, int> p = q.front();
            flip.push_back({p.first, p.second});
            
            for (int i = 0; i < 4; i++){
                int xS = p.first + tx[i], yS = p.second + ty[i];
                if (xS < 0 || yS < 0 || xS == n || yS == m){
                    hasil = false;
                    continue;
                }

                if (!pernah[xS][yS] && mat[xS][yS] == 0){
                    pernah[xS][yS] = true;
                    q.push({xS, yS});
                    flip.push_back({xS, yS});
                }
            }

            q.pop();
        }

        return hasil;
    }

    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if (board[x][y] == 'X'){
                    mat[x][y] = 1;
                }
            }
        }

        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if (!pernah[x][y] && mat[x][y] == 0){
                    bool bisa1 = BFS(x, y);
                    if (bisa1){
                        for (int i = 0; i < flip.size(); i++){
                            board[flip[i].first][flip[i].second] = 'X';
                        }
                    }

                    flip.clear();
                }
            }
        }
    }
};