class Solution {
public:
    // dimar's solution
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> bisa(n);
        bisa[0] = 1;
        for (int x = 1; x < n; x++){
            int i = 1;
            for (int y = x - 1; y >= 0; y--) {
                if (i <= nums[y] && bisa[y]) {
                    bisa[x] = 1;
                    break;
                }

                i++;
            }
        }

        return bisa[n - 1];
    }
};