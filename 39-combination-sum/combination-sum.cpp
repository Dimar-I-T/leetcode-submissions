class Solution {
public:
    // dimar's solution
    using vvi = vector<vector<int>>;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int c = candidates.size(), t = target;
        vector<vector<vvi>> dp;
        vector<int> ca(c + 1);
        for (int x = 1; x <= c; x++){
            ca[x] = candidates[x - 1];
        }

        dp.resize(t + 1, vector<vvi>(c + 1));
        for (int x = 0; x <= t; x++){
            for (int y = 1; y <= c; y++){
                dp[x][y] = {{}};
            }
        }

        for (int x = 1; x <= t; x++){
            for (int y = 1; y <= c; y++){
                int k = x - ca[y];
                set<vector<int>> v;
                if (k >= 0){
                    for (auto isi: dp[k][c]){
                        vector<int> temp = isi;
                        if (k == 0 || !temp.empty()){
                            temp.push_back(ca[y]);
                        }

                        sort(temp.begin(), temp.end());
                        v.insert(temp);
                    }
                }

                for (auto isi: dp[x][y - 1]){
                    v.insert(isi);
                }

                for (auto isi: v){
                    dp[x][y].push_back(isi);
                }
            }
        }

        vvi hasil;
        for (auto isi: dp[t][c]){
            if (!isi.empty()){
                hasil.push_back(isi);
            }
        }

        return hasil;
    }
};