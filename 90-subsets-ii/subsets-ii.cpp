class Solution {
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            size_t seed = v.size();
            for (int x : v) {
                seed ^= std::hash<int>()(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    unordered_map<vector<int>, bool, VectorHash> visited;

    void isi(vector<int> kiri, vector<int> kanan, vector<vector<int>>& hasil) {
        if (!visited[kiri]) {
            hasil.push_back(kiri);
        }

        visited[kiri] = 1;
        int nKiri = kiri.size();
        int nKanan = kanan.size();
        for (int x = 0; x < nKanan; x++) {
            vector<int> kiriNext = kiri;
            vector<int> kananNext;
            for (int y = 0; y < nKanan; y++) {
                if (x == y) {
                    continue;
                }

                kananNext.push_back(kanan[y]);
            }

            if (!kiri.empty()) {
                if (kiri[nKiri - 1] <= kanan[x]) {
                    kiriNext.push_back(kanan[x]);
                } else {
                    continue;
                }
            } else {
                kiriNext.push_back(kanan[x]);
            }

            isi(kiriNext, kananNext, hasil);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> hasil;
        isi({}, nums, hasil);
        return hasil;
    }
};