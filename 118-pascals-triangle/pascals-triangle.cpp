class Solution {
public:
    // dimar's solution
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> hasil;
        hasil.push_back({1});
        for (int x = 1; x < numRows; x++){
            hasil.push_back({1});
            for (int y = 1; y < hasil[x - 1].size(); y++){
                hasil[x].push_back(hasil[x - 1][y] + hasil[x - 1][y - 1]);
            }

            hasil[x].push_back(1);
        }

        return hasil;
    }
};