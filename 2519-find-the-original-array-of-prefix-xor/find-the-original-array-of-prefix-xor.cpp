class Solution {
public:
    // dimar's solution
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> hasil(n);
        hasil[0] = pref[0];
        for (int x = 1; x < n; x++){
            hasil[x] = pref[x - 1] ^ pref[x];
        }

        return hasil;
    }
};