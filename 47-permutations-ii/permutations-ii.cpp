class Solution {
public:
    // dimar's solution
    set<vector<int>> hasil;
    void permutasi(vector<int> kiri, vector<int> kanan) {
        int n = kanan.size();
        int m = kiri.size();
        if (n == 0) {
            return;
        }

        kiri.push_back(0);
        vector<int> kiri1 = kiri;
        for (int x = 0; x < n; x++) {
            kiri1[m] = kanan[x];
            vector<int> kanan1;
            for (int y = 0; y < n; y++) {
                if (y == x) {
                    continue;
                }

                kanan1.push_back(kanan[y]);
            }

            vector<int> perm;
            for (int y : kiri1) {
                perm.push_back(y);
            }

            for (int y : kanan1) {
                perm.push_back(y);
            }

            hasil.insert(perm);
            permutasi(kiri1, kanan1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutasi({}, nums);
        vector<vector<int>> hasilV;
        for (vector<int> v : hasil) {
            hasilV.push_back(v);
        }

        return hasilV;
    }
};