class Solution {
public:
    // dimar's solution
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> hasil;
        hasil.push_back({1});
        for (int x = 0; x < rowIndex; x++){
            vector<int> sem = hasil[0], sek;
            hasil.pop_back();
            sek.push_back(1);
            for (int y = 1; y < sem.size(); y++){
                sek.push_back(sem[y] + sem[y - 1]);
            }

            sek.push_back(1);
            hasil.push_back(sek);
        }

        return hasil[0];
    }
};