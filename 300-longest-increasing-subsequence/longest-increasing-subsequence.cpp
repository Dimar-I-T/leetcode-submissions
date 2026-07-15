class Solution {
public:
    // dimar's solution
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n);
        LIS[0] = 1;
        int hasil = 1;
        for (int x = 1; x < n; x++){
            LIS[x] = 1;
            for (int y = x - 1; y >= 0; y--){
                if (nums[x] > nums[y]){
                    LIS[x] = max(LIS[x], 1 + LIS[y]);
                }
            }

            hasil = max(hasil, LIS[x]);
        }

        return hasil;
    }
};