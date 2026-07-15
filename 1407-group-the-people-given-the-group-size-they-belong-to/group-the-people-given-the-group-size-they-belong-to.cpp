class Solution {
public:
    // dimar's solution
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        set<int> banyak;
        unordered_map<int, vector<int>> banyak_kelompok;
        unordered_map<int, int> bb;
        int n = groupSizes.size();
        for (int x = 0; x < n; x++){
            banyak.insert(groupSizes[x]);
            bb[groupSizes[x]]++;
            banyak_kelompok[groupSizes[x]].push_back(x);
        }

        vector<vector<int>> hasil;
        for (auto x = banyak.begin(); x != banyak.end(); ++x){
            int b = *x;
            int a = 0;
            vector<int> A;
            for (int y = 1; y <= bb[b]; y++){
                A.push_back(banyak_kelompok[b][a]);
                if (y % b == 0){
                    hasil.push_back(A);
                    A.clear();
                }
                
                a++;
            }
        }

        return hasil;
    }
};