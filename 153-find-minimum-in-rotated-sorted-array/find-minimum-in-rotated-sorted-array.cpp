class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int res = -INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            int curr = nums[mid];
            int right = INT_MAX;
            int left = INT_MAX;
            if (mid > 0) {
                left = nums[mid - 1];
            }

            if (mid < n - 1) {
                right = nums[mid + 1];
            }

            int mostLeft = nums[n - 1];
            if (curr > right && curr > left) {
                res = min(left, right);
                break;
            }

            if (curr < right && curr < left) {
                res = curr;
                break;
            }

            if (curr < mostLeft) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

            res = curr;
        }

        return res;
    }
};