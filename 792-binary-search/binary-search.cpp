class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int curr = nums[m];
            if (target == curr) {
                res = m;
                break;
            }

            if (target > curr) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};