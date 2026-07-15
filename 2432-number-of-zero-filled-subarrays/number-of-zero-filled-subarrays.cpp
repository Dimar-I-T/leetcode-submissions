class Solution {
public:
    // dimar's solution
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long dp[100001] = {0};
        int k = 0;
        long long hasil = 0;
        if (nums[0] == 0){
            k = 1;
            dp[0] = 1;
        }

        for (int x = 1; x < n; x++){
            if (nums[x] == 0){
                k++;
                dp[x] = dp[x - 1] + k;
                //cout << x << " " << dp[x] << "\n";
            }else{
                k = 0;
                hasil += dp[x - 1];
            }
        }

        hasil += dp[n - 1];
        return hasil;
    }
};