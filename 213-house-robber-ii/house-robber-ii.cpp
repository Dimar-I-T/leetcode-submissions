class Solution {
public:
    // dimar's solution
    int DP(vector<int> v){
        int n = v.size();
        vector<int> dp(n);
        dp[n - 1] = v[n - 1];
        int hasil = dp[n - 1];
        for (int x = n - 2; x >= 0; x--){
            int maks = 0;
            dp[x] = v[x];
            for (int y = x + 2; y < n; y++){
                maks = max(maks, dp[y]);
            }

            dp[x] += maks;
            hasil = max(hasil, dp[x]);
        }

        return hasil;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }

        vector<int> v1, v2;
        for (int x = 0; x < n - 1; x++){
            v1.push_back(nums[x]);
            v2.push_back(nums[x + 1]);
        }

        return max(DP(v1), DP(v2));
    }
};