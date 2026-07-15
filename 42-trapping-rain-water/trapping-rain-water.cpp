class Solution {
public:
    // dimar's solution
    int trap(vector<int>& height) {
        int n = height.size(), hasil = 0;
        vector<int> kiri(n), kanan(n);
        kiri[0] = height[0];
        for (int x = 1; x < n; x++){
            kiri[x] = max(kiri[x - 1], height[x]);
        }

        kanan[n - 1] = height[n - 1];
        for (int x = n - 2; x >= 0; x--){
            kanan[x] = max(kanan[x + 1], height[x]);
        }

        for (int x = 0; x < n; x++){
            hasil += min(kiri[x], kanan[x]) - height[x];
        }

        return hasil;
    }
};