class Solution {
public:
    // dimar's solution
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n - 1] = nums[n - 1];
        int hasil = dp[n - 1];
        for (int x = n - 2; x >= 0; x--){
            dp[x] = nums[x];
            int maks = 0;
            for (int y = x + 2; y < n; y++){
                maks = max(maks, dp[y]);
            }

            dp[x] += maks;
            hasil = max(hasil, dp[x]);
        }

        return hasil;
    }
};