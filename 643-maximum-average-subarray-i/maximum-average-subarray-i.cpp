class Solution {
public:
    // dimar's solution
    double findMaxAverage(vector<int>& nums, int k) {
        double jumlah = 0, hasil = 0;
        int n = nums.size();
        for (int x = 0; x < k; x++){
            jumlah += nums[x];
        }

        hasil = jumlah/k;
        for (int x = 0; x < n - k; x++){
            jumlah -= nums[x];
            jumlah += nums[x + k];
            hasil = max(hasil, jumlah/k);
        }

        return hasil;
    }
};