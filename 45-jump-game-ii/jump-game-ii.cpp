class Solution {
public:
    // dimar's solution
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int x = 1; x < n; x++) {
            int i = 1;
            for (int y = x - 1; y >= 0; y--) {
                if (i <= nums[y]) {
                    dp[x] = min(dp[x], dp[y] + 1);
                }

                i++;
            }
        }

        // for (int x = 0; x < n; x++) {
        //     cout << dp[x] << " ";
        // }

        return dp[n - 1];
    }
};