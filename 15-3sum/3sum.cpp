class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int prevX = -INT_MAX;
        for (int x = 0; x < n; x++) {
            int l = x + 1;
            if (prevX == nums[x]) {
                continue;
            }

            int r = n - 1;
            int t = -nums[x];
            int prevL = -INT_MAX;
            int prevR = -INT_MAX;
            while (l < r) {
                if (l == x) {
                    l++;
                    continue;
                }

                if (r == x) {
                    r--;
                    continue;
                }

                int left = nums[l];
                int right = nums[r];
                int sum = left + right;
                if (prevL == left) {
                    l++;
                    continue;
                }

                if (prevR == right) {
                    r--;
                    continue;
                }

                if (sum == t) {
                    vector<int> resSem = {nums[x], left, right};
                    sort(resSem.begin(), resSem.end());
                    res.push_back(resSem);
                    prevL = left;
                    prevR = right;
                    l++;
                    continue;
                }

                if (sum < t) {
                    prevL = left;
                    l++;
                    continue;
                }

                if (sum > t) {
                    prevR = right;
                    r--;
                    continue;
                }
            }

            prevX = nums[x];
        }

        return res;
    }
};